#include "Day5.h"

void day5()
{
	std::cout << "Doing second problem" << '\n' << '\n';
	day5_1_soln();
	std::cout << '\n' << '\n' << "Doing second problem" << '\n' << '\n';
	day5_2_soln();
}

void day5_1_soln()
{
	DAY_5_2_SOLN = false;
	std::cout << "Doing test " << '\n';
	std::vector<Segment>* segments_test = parseCoordinates("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day5\\segments_test.txt");
	std::cout << countNumberOfPointsThatOverlap(segments_test);
	std::cout << '\n' << '\n' << "Doing problem " << '\n';
	std::vector<Segment>* segments = parseCoordinates("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day5\\segments.txt");
	std::cout << countNumberOfPointsThatOverlap(segments);
}

void day5_2_soln()
{
	DAY_5_2_SOLN = true;
	std::cout << "Doing test " << '\n';
	std::vector<Segment>* segments_test = parseCoordinates("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day5\\segments_test.txt");
	std::cout << countNumberOfPointsThatOverlap(segments_test);
	std::cout << '\n' << '\n' << "Doing problem " << '\n';
	std::vector<Segment>* segments = parseCoordinates("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day5\\segments.txt");
	std::cout << countNumberOfPointsThatOverlap(segments);
}

int countNumberOfPointsThatOverlap(std::vector<Segment>* segments)
{
	std::map<std::pair<int, int>, int>* counts = new std::map<std::pair<int, int>, int>();
	for (int i = 0; i < segments->size(); i++)
	{
		Segment segment = segments->at(i);
		std::vector<std::pair<int, int>>* points = segment.pointsOnSegment(); 
		for (int j = 0; j < points->size(); j++)
		{
			std::pair<int, int> const point = points->at(j);
			if (counts->find(point) == counts->end())
			{
				counts->insert(std::initializer_list<std::pair<std::pair<int, int> const, int>>{
					std::pair<std::pair<int, int> const, int>{point, 0}});
			}
			counts->at(point) += 1;
		}
	}

	int numPointsWithAtLeastTwoOverlaps = 0;
	for (std::map<std::pair<int, int>, int>::iterator it = counts->begin(); it != counts->end(); it++)
	{
		if (it->second >= 2)
		{
			numPointsWithAtLeastTwoOverlaps++;
		}
	}
	return numPointsWithAtLeastTwoOverlaps;
}

Segment::Segment(std::string xPointStr, std::string yPointStr)
{
	X = *parsePointStr(xPointStr);
	Y = *parsePointStr(yPointStr);
}

std::pair<int, int>* Segment::parsePointStr(std::string pointStr)
{
	while (pointStr.find_first_of(' ') == 0)
	{
		pointStr.erase(0, 1);
	}
	while (pointStr.find_last_of(' ') == pointStr.length() - 1)
	{
		pointStr.erase(pointStr.length() - 1, 1);
	}

	char comma = ',';
	int commaIndex = pointStr.find_first_of(comma);
	std::string xCoordString = pointStr.substr(0, commaIndex);
	std::string yCoordString = pointStr.substr(commaIndex + 1);

	return new std::pair<int, int>(std::stoi(xCoordString), std::stoi(yCoordString));
}

std::vector<Segment>* parseCoordinates(std::string filePath)
{
	std::vector<Segment>* retval = new std::vector<Segment>();

	std::ifstream inFile;
	inFile.open(filePath);
	
	std::string divider = " -> ";
	int dividerLength = divider.length();
	std::string line;

	while (std::getline(inFile, line))
	{
		int pos = line.find_first_of(divider);
		std::string xPointStr = line.substr(0, pos);
		std::string yPointStr = line.substr(pos + dividerLength);
		retval->push_back(Segment(xPointStr, yPointStr));
	}
	return retval;
}

std::vector<std::pair<int, int>>* Segment::pointsOnSegment()
{
	if (X.first == Y.first)
	{
		std::vector<std::pair<int, int>>* retval = new std::vector<std::pair<int, int>>();

		int left = X.second;
		int right = Y.second;
		if (left > right)
		{
			left = Y.second;
			right = X.second;
		}

		for (int i = left; i <= right; i++)
		{
			retval->push_back(std::pair<int, int>{X.first, i});
		}
		return retval;
	}

	if (X.second == Y.second)
	{
		std::vector<std::pair<int, int>>* retval = new std::vector<std::pair<int, int>>();

		int lower = X.first;
		int higher = Y.first;
		if (lower > higher)
		{
			lower = Y.first;
			higher = X.first;
		}

		for (int i = lower; i <= higher; i++)
		{
			retval->push_back(std::pair<int, int>{i, X.second});
		}
		return retval;
	}

	if (std::abs(X.first - Y.first) == std::abs(X.second - Y.second)
	  && DAY_5_2_SOLN)
	{
		std::vector<std::pair<int, int>>* retval = new std::vector<std::pair<int, int>>();

		int left = X.first;
		int leftY = X.second;
		int right = Y.first;
		int rightY = Y.second;
		if (left > right)
		{
			left = Y.first;
			leftY = Y.second;
			right = X.first;
			rightY = X.second;
		}

		int gradient = 1;
		if (rightY < leftY)
		{
			gradient = -1;
		}

		for (int i = 0; i <= right-left; i++)
		{
			retval->push_back(std::pair<int, int>{left + i, leftY + gradient*i});
		}
		return retval;
	}

	//This logging is spamming up the console.
	if (DAY_5_2_SOLN)
	{
		//std::cout << "ERROR: Points method not implemented for non vertical/horizontal/45degDiagonal lines" << '\n';
	}
	else
	{
		//std::cout << "ERROR: Points method not implemented for non vertical/horizontal lines" << '\n';
	}
	
	return new std::vector<std::pair<int, int>>();
}