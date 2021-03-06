#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

extern std::vector<std::string> *parseDelimitedStringToVector(std::string str, char delimiter);
extern std::vector<int>* parseDelimitedStringToIntVector(std::string str, char delimiter);
extern std::vector<int>* parseStringToOneDigitInts(std::string str);
extern std::vector<char>* getFromFirstWhereNotInSecond(std::string first, std::string second);
extern std::string getFromFirstWhereNotInSecondStr(std::string first, std::string second);
extern bool areAnagrams(std::string first, std::string second);