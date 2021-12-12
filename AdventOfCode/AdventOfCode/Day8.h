#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>>
#include <map>

#include "StringUtils.h"

const static int CONNECTIONS_0 = 6;
const static int CONNECTIONS_1 = 2;
const static int CONNECTIONS_2 = 5;
const static int CONNECTIONS_3 = 5;
const static int CONNECTIONS_4 = 4;
const static int CONNECTIONS_5 = 5;
const static int CONNECTIONS_6 = 6;
const static int CONNECTIONS_7 = 3;
const static int CONNECTIONS_8 = 7;
const static int CONNECTIONS_9 = 6;

extern void day8();
extern void day8_1_soln();
extern void day8_2_soln();

struct SegmentDisplayResult
{
public:
	std::vector<std::string> numberWirings;
	std::vector<std::string> digitCodesDisplayed;
	std::map<std::string, std::string> anagramMap;

	SegmentDisplayResult(std::string line); //construct from a string

	int solve();

private:
	void parse(std::string line); //parse a string to a result(called in the constructor)
	std::vector<std::string>* getWiringsForLength(int length);
	void initializeAnagramMap();
};

extern std::vector<SegmentDisplayResult*>* parseFromFile(std::string filePath);
extern bool isAUniqueLength(std::string digitCodeStr);