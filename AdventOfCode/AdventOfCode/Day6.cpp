#include "Day6.h"

void day6()
{
	std::cout << "First problem: " << '\n';
	day6_1_soln();
	std::cout << '\n' << "Second problem: " << '\n';
	day6_2_soln();
}

void day6_1_soln()
{
	//std::vector<LanternFish*>* initialPopulation_test = getFishFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day6\\LanternFish_test.txt");
	//simulateLanternFishPopulation(initialPopulation_test, 80);
	std::vector<LanternFish*>* initialPopulation = getFishFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day6\\LanternFish.txt");
	simulateLanternFishPopulation(initialPopulation, 18);
}

void day6_2_soln()
{
	std::vector<int>* initialAges = parseFileToIntVec("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day6\\LanternFish.txt");
	simulateLanternFishPopulationFastWay(initialAges, 256);
}

void simulateLanternFishPopulation(std::vector<LanternFish*>* initialPopulation, int numDays)
{
	std::vector<LanternFish*>* population = &(*initialPopulation);
	for (int i = 0; i < numDays; i++)
	{
		std::vector<LanternFish*>* newBirths = new std::vector<LanternFish*>();
		for (int j = 0; j < population->size(); j++)
		{
			LanternFish* baby = population->at(j)->update();
			if (baby != nullptr)
			{
				newBirths->push_back(baby);
			}
		}
		population->insert(population->end(), newBirths->begin(), newBirths->end());
	}
	std::cout << population->size();
}

void simulateLanternFishPopulationFastWay(std::vector<int>* initialFishAges, int numDays)
{
	std::map<int, long long>* fishPools = new std::map<int, long long>();

	for (int i = 0; i < 9; i++)
	{
		fishPools->insert(std::initializer_list<std::pair<const int, long long>>{std::pair<const int, long long>{i, 0}});
	}

	for (int i = 0; i < initialFishAges->size(); i++)
	{
		int age = initialFishAges->at(i);
		fishPools->at(age) += 1;
	}

	for (int i = 0; i < numDays; i++)
	{
		long long fishAtZero = fishPools->at(0);
		for (int j = 1; j < 9; j++)
		{
			fishPools->at(j - 1) = fishPools->at(j);
		}
		fishPools->at(6) += fishAtZero;
		fishPools->at(8) = fishAtZero;
	}

	long long total = 0;
	for (int i = 0; i < 9; i++)
	{
		total += fishPools->at(i);
	}
	std::cout << total;
}

std::vector<LanternFish*>* getFishFromFile(std::string filePath)
{
	std::vector<LanternFish*>* retval = new std::vector<LanternFish*>();
	std::vector<int>* intVec = parseFileToIntVec(filePath);

	for (int i = 0; i < intVec->size(); i++)
	{
		retval->push_back(new LanternFish(intVec->at(i)));
	}
	return retval;
}

std::vector<int>* parseFileToIntVec(std::string filePath)
{
	std::vector<int>* retval = new std::vector<int>();

	std::ifstream inFile;
	inFile.open(filePath);

	if (inFile.fail())
	{
		std::cout << "ERROR: File not found" << '\n';
		return retval;
	}

	char c;
	std::string numAsStr = "";
	while (inFile.get(c))
	{
		if (c != ',')
		{
			numAsStr += c;
		}

		if (c == ','
			|| inFile.peek() == std::ifstream::traits_type::eof())
		{
			int internalCounter = std::stoi(numAsStr);
			numAsStr = "";
			retval->push_back(internalCounter);
		}
	}
	return retval;
}

LanternFish::LanternFish(int internalTimer)
{
	this->internalTimer = internalTimer;
}
LanternFish* LanternFish::update()
{
	if (internalTimer == 0)
	{
		internalTimer = TIMER_RESET_VALUE;
		return new LanternFish{ BABY_START_TIMER };
	}
	
	internalTimer--;
	return nullptr;
}