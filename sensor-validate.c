#include "sensor-validate.h"

#define TRUE    1
#define FALSE   0

int IsDifferenceMoreThanMaxDelta(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 1;
  }
  return 0;
}


inline int IsChangeinValuesAbrupt (double* values, int numOfValues, double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(IsDifferenceMoreThanMaxDelta(values[i], values[i + 1],maxDelta) == FALSE) {
      return 1;
    }
  }
  return 0;
}


int validateSOCreadings(double* values, int numOfValues)
{
  int IsValidationPassed = TRUE;
  double maxDeltabetweenReadings = 0.05 ;

  if(IsChangeinValuesAbrupt(values,numOfValues,maxDeltabetweenReadings) == TRUE)
  {
    IsValidationPassed = FALSE;
  }
  return IsValidationPassed;  
}

int validateCurrentreadings(double* values, int numOfValues)
{
  int IsValidationPassed = TRUE;
  double maxDeltabetweenReadings = 0.1 ;

  if(IsChangeinValuesAbrupt(values,numOfValues,maxDeltabetweenReadings) == TRUE)
  {
    IsValidationPassed = FALSE;
  }
  return IsValidationPassed; 
}
