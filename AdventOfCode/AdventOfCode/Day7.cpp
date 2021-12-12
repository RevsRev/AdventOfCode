#include "Day7.h"

void day7()
{
	std::cout << "Doing first problem: " << '\n';
	day7_1_soln();
	std::cout << '\n' << '\n';
	std::cout << "Doing second problem:" << '\n';
	day7_2_soln();
}

void day7_1_soln()
{
	std::vector<int>* numbers = parseFileToIntVec("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day7\\numbers.txt");
	int median = findMedian(numbers);
	std::cout << calculateOffset(numbers, median);
}

void day7_2_soln()
{
	std::vector<int>* numbers = parseFileToIntVec("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day7\\numbers.txt");
	std::sort(numbers->begin(), numbers->end()); //sorting just to easily find the min and max.
	int min = numbers->at(0);
	int max = numbers->at(numbers->size() - 1);

	std::vector<int>* offsets = new std::vector<int>();
	for (int i=min; i<=max; i++)
	{
		offsets->push_back(calculateOffset2(numbers, i));
	}
	std::sort(offsets->begin(), offsets->end());
	std::cout << offsets->at(0);
}

int findMedian(std::vector<int>* numbers)
{
	std::sort(numbers->begin(), numbers->end());
	int index = (numbers->size() + 1) / 2;
	return numbers->at(index-1); //because indices start at zero.
}

int calculateOffset(std::vector<int>* numbers, int peg)
{
	int retval = 0;
	for (int i = 0; i < numbers->size(); i++)
	{
		retval += std::abs(peg - numbers->at(i));
	}
	return retval;
}

int calculateOffset2(std::vector<int>* numbers, int peg)
{
	int retval = 0;
	for (int i = 0; i < numbers->size(); i++)
	{
		int dif = std::abs(peg - numbers->at(i));
		retval += dif * (dif + 1) / 2;//sum of consecutive integers
	}
	return retval;
}