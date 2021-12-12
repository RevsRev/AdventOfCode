#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

extern const std::vector<std::string> bits_test;
extern const std::vector<std::string> bits;

extern void day3();
extern void day3_1_soln();
extern void day3_2_soln();

extern void processBitVector3_1(std::vector<std::string> bitArray);
extern void processBitVector3_2(std::vector<std::string> bitArray);
extern std::vector<std::string> cullBits(std::vector<std::string> bitArray, int bitIndexToCull, char bitToBeCulledStr);
extern std::vector<int> getBitCounts(std::vector<std::string> bitArray);
extern int convertBinaryArrayToDecimal(std::vector<int> binArray);
extern int convertBinaryArrayToDecimal(std::string binArray);