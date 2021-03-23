#include "sensor-validate.h"

int IsDifferenceNotMoreThanMaxDelta(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int IsListConsecutiveValuesDiffNotMoreThanMaxDelta (double* values, int numOfValues, double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(IsDifferenceNotMoreThanMaxDelta(values[i], values[i + 1],maxDelta) == 0) {
      return 0;
    }
  }
  return 0;
}


int validateSOCreadings(double* values, int numOfValues) {
  double SOCReadings_maxDelta = 0.05 ;
  return IsListConsecutiveValuesDiffMoreThanMaxDelta(values,numOfValues, SOCReadings_maxDelta); 
}

int validateCurrentreadings(double* values, int numOfValues) {
  double CurrentReadings_maxDelta = 0.1 ;
  return IsListConsecutiveValuesDiffNotMoreThanMaxDelta(values,numOfValues, CurrentReadings_maxDelta); 
}
