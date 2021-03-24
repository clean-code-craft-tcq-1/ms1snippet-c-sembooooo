#include "sensor-validate.h"

#define TRUE    1
#define FALSE   0

int IsDifferenceMoreThanMaxDelta(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return TRUE;
  }
  return FALSE;
}


int IsChangeinValuesAbrupt (double* values, int numOfValues, double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;
  assert(values!= 0);
  for(int i = 0; i < lastButOneIndex; i++) {
    if(IsDifferenceMoreThanMaxDelta(values[i], values[i + 1],maxDelta) == TRUE) {
      return TRUE;
    }
  }
  return FALSE;
}


int validateSOCreadings(double* values, int numOfValues)
{
  int IsValidationPassed = TRUE;
  double maxDeltabetweenValues = 0.05 ;
  if(IsChangeinValuesAbrupt(values,numOfValues,maxDeltabetweenValues) == TRUE)
  {
    IsValidationPassed = FALSE;
  }
  return IsValidationPassed;  
}

int validateCurrentreadings(double* values, int numOfValues)
{
  int IsValidationPassed = TRUE;
  double maxDeltabetweenValues = 0.1 ;

  if(IsChangeinValuesAbrupt(values,numOfValues,maxDeltabetweenValues) == TRUE)
  {
    IsValidationPassed = FALSE;
  }
  return IsValidationPassed; 
}

