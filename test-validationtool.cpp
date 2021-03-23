#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 0);
}

TEST_CASE("reports sucess when a smooth transition present in soc ") {
  double socReadings[] = {0.0, 0.01, 0.02, 0.03};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 1);
}

TEST_CASE("reports sucess when a smooth transition present in soc ") {
  double socReadings[] = {0.0, 0.01, 0.02, 0.03};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 1);
}


TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSOCreadings(currentReadings, numOfCurReadings) == 0);
}


TEST_CASE("reports sucess when a smooth transition present in current") {
  double currentReadings[] = {0.0, 0.1, 0.2, 0.3};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSOCreadings(currentReadings, numOfCurReadings) == 1);
}

TEST_CASE("Checks if assertion is failed during null pointer as parameter ") {
  double *Readings = 0;
  int numOfReadings = 10 /*dummy value */
  double maxDelta = 5.0;
  REQUIRE_THROWS(IsChangeinValuesAbrupt(Readings,numOfReadings,maxDelta));
}