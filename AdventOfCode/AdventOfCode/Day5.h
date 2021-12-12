#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

extern class Segment
{
	//A line segment from X to Y
	std::pair<int, int> X;
	std::pair<int, int> Y;

	std::pair<int, int>* parsePointStr(std::string pointStr);

public:
	Segment(std::string xPointStr, std::string yPointStr);
	std::vector<std::pair<int,int>> *pointsOnSegment();
};

static bool DAY_5_2_SOLN = false;
extern std::vector<Segment> *parseCoordinates(std::string filePath);
extern void day5();
extern void day5_1_soln();
extern void day5_2_soln();
extern int countNumberOfPointsThatOverlap(std::vector<Segment>* segments);
