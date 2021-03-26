# Charge Validation Tool

This is a tool to validate charging parameters.

Given a set of values, it checks if they have 'sudden jumps'.
Such jumps indicate a failed / noisy sensor.

## Tasks

1. The 'No Duplications' check is failing. Resolve the duplication.
1. Give a good name to the function `_give_me_a_good_name`.
It is a boolean function, used in `if` statements.
Ensure that the `if` statement reads like a sentence after you rename the function.
1. The `values` parameter, given to the `validate...` function can be null.
Currently, the code does not handle that.
Ensure the code ignores a call with a null-pointer and add a test for that.

## Changes -Sana Srikar

The below function returns 0 if difference is greater than MaxDelta.
```
    int _give_me_a_good_name(double value, double nextValue, double maxDelta) {
    if(nextValue - value > maxDelta) {
        return 0;
    }
    return 1;
    }
```

This is inreturn used in `validateSOCreadings` and `validateCurrentreadings` but 
with a negation

```
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!_give_me_a_good_name(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
```
Meaning a check is being performed to know if the difference is not more than maxdelta.
If the difference is greater than maxdelta then `validateSOCreadings` and `validateCurrentreadings`
are reporting 0 . Was not sure how to interpret that magical number.
But the below testcase helped me in understanding that 0 - fail and 1 - pass.
```
TEST_CASE("reports error when soc jumps abruptly") {

```
So basically we are checking if the difference is more than maxdelta and if it is then we are reporting failure.
Hence i have modified the code a little for better understanding (and easy naming ).


```
    int IsDifferenceMoreThanMaxDelta(double value, double nextValue, double maxDelta) {
    if(nextValue - value > maxDelta) {
    return TRUE;    /* old code returns 0 here */
    }
    return FALSE;     /* old code returns 1 here */
    }
```

As there was code duplicaton made one more function and assert check for the pointer
Named it `IsChangeinValuesAbrupt` than `IsChangeinValuesSudden` or something else 
as abrupt at that moment sounded more like context based.
Even `IsChangeinReadingsAbrupt` also sounds good.

```
    int IsChangeinValuesAbrupt (double* values, int numOfValues, double maxDelta)
    {
    int lastButOneIndex = numOfValues - 1;
    assert(values!= 0);
    for(int i = 0; i < lastButOneIndex; i++) {
        /*old code negation was removed as it makes it harder to read too -i think. */
        if(IsDifferenceMoreThanMaxDelta(values[i], values[i + 1],maxDelta) == TRUE) { 
            /* returns TRUE during abrupt change in values */
        return TRUE;
        }
    }
    return FALSE;
    }
```

As magical numbers 1 and 0 are not readable i implemented two very simple macros `TRUE`
and `FALSE`.

According to me`validateSOCreadings` and `validateCurrentreadings` are bad names.
Better names would be a context based such as `IsSOCReadingsPlausible()` and 
`IsCurrentReadingsPlausible`






