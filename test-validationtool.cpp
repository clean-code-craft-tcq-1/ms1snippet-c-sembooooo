#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

/**************************************************************************************
 *                            SOC Readings Related Testcases
 **************************************************************************************/ 

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(IsSOCReadingsPlausible(socReadings, numOfSocReadings) == 0);
}

TEST_CASE("reports error when list is not being traversed completely in SOC") {
  double socReadings[] = {0.0, 0.01, 0.02, 0.5};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(IsSOCReadingsPlausible(socReadings, numOfSocReadings) == 0);
}

TEST_CASE("reports sucess when a smooth transition present in soc ") {
  double socReadings[] = {0.0, 0.01, 0.02, 0.03};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(IsSOCReadingsPlausible(socReadings, numOfSocReadings) == 1);
}

/**************************************************************************************
 *                            Current Readings Related Testcases
 **************************************************************************************/ 

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(IsCurrentReadingsPlausible(currentReadings, numOfCurReadings) == 0);
}


TEST_CASE("reports sucess when a smooth transition present in current") {
  double currentReadings[] = {0.0, 0.1, 0.2, 0.3};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(IsCurrentReadingsPlausible(currentReadings, numOfCurReadings) == 1);
}

#if 0
/**
https://stackoverflow.com/questions/38533272/use-c-catch-framework-to-verify-assert-statement

not really sure how to write this testcase. 
sigabort() exception is raised. i think because of this whole .exe is aborting.
Is there a way to catch that it ? 
No idea about C++(with a little knowledge in python) as REQUIRE_THROWS() is using try and catch blocks
and as .exe is from C++ , how come it is not being catched ? 
is it because c - assert() does something which C++ assert() doesnt do ?
*/

TEST_CASE("Checks if assertion is failed during null pointer as parameter ") {
  double *Readings = 0;
  int numOfReadings = 10; /*dummy value */
  double maxDelta = 5.0;
  REQUIRE_THROWS(IsChangeinValuesAbrupt(Readings,numOfReadings,maxDelta));
}
#endif