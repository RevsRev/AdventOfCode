#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StringUtils.h"
#include <algorithm>

extern void day9();
extern void day9_1_soln();
extern void day9_2_soln();

class HeightMap
{
private:
	std::vector<std::vector<int>*>* heightArray;
	int width;
	int height;

public:
	HeightMap(std::vector<std::vector<int>*>* heightArray, int width, int height);
	std::vector<std::pair<int, int>>* getLowPoints();
	std::vector < std::vector<std::pair<int, int>>*>* getBasins();
	int sumPoints(std::vector<std::pair<int, int>>* points);
};

extern HeightMap* day9_parseFromFile(std::string filePath);