#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

class LanternFish
{
	int internalTimer;
	const static int TIMER_RESET_VALUE = 6;
	const static int BABY_START_TIMER = 8;
public:
	LanternFish(int internalTimer);
	LanternFish* update();
};

extern void day6();
extern void day6_1_soln();
extern void day6_2_soln();

extern std::vector<LanternFish*>* getFishFromFile(std::string filePath);
extern std::vector<int>* parseFileToIntVec(std::string filepath);
extern void simulateLanternFishPopulation(std::vector<LanternFish*>* population, int numDays);
extern void simulateLanternFishPopulationFastWay(std::vector<int>* initialFishAges, int numDays);