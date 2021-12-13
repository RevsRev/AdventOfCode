#include "Day9.h"

void day9()
{
	day9_1_soln();
	std::cout << '\n' << '\n';
	day9_2_soln();
}

void day9_1_soln()
{
	HeightMap* heightMap = day9_parseFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day9\\heightMap.txt");
	std::vector<std::pair<int, int>>* lowPoints = heightMap->getLowPoints();
	int lowPointsSum = heightMap->sumPoints(lowPoints);
	std::cout << lowPointsSum + lowPoints->size();
}

void day9_2_soln()
{
	HeightMap* heightMap = day9_parseFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day9\\heightMap.txt");
	std::vector<std::vector<std::pair<int, int>>*>* basins = heightMap->getBasins();
	std::vector<int>* basinsSize = new std::vector<int>();
	for (int i = 0; i < basins->size(); i++)
	{
		basinsSize->push_back(basins->at(i)->size());
	}
	std::sort(basinsSize->begin(), basinsSize->end());

	int prod = 1;
	for (int i = 1; i <= 3; i++)
	{
		prod *= basinsSize->at(basinsSize->size() - i);
	}
	std::cout << prod;
}

HeightMap* day9_parseFromFile(std::string filePath)
{
	std::fstream inFile;
	inFile.open(filePath);

	if (inFile.fail())
	{
		std::cout << "ERROR: File not found" << '\n';
		return nullptr;
	}

	std::vector<std::vector<int>*>* heightArray = new std::vector<std::vector<int>*>();

	std::string line;
	while (std::getline(inFile, line))
	{
		std::vector<int>* lineAsInts = parseStringToOneDigitInts(line);
		heightArray->push_back(lineAsInts);
	}
	return new HeightMap(heightArray, heightArray->at(0)->size(), heightArray->size());
}

HeightMap::HeightMap(std::vector<std::vector<int>*>* heightArray, int width, int height)
{
	this->heightArray = heightArray;
	this->width = width;
	this->height = height;
}

std::vector<std::pair<int, int>>* HeightMap::getLowPoints()
{
	std::vector<std::pair<int, int>>* retval = new std::vector<std::pair<int, int>>();

	for (int i = 0; i < height; i++)
	{
		int heightCheckUpper = i - (i != 0);
		int heightCheckLower = i + (i != height-1);
		for (int j = 0; j < width; j++)
		{
			int pointHeight = heightArray->at(i)->at(j);

			int widthCheckLeft = j - (j != 0);
			int widthCheckRight = j + (j != width-1);

			bool isLowPoint = true;
			for (int a = heightCheckUpper; a <= heightCheckLower && isLowPoint; a++)
			{
				if (a == i)
				{
					continue;
				}

				int adjHeight = heightArray->at(a)->at(j);
				if (adjHeight <= pointHeight)
				{
					isLowPoint = false;
				}
			}

			for (int a = widthCheckLeft; a <= widthCheckRight && isLowPoint; a++)
			{
				if (a == j)
				{
					continue;
				}

				int adjHeight = heightArray->at(i)->at(a);
				if (adjHeight <= pointHeight)
				{
					isLowPoint = false;
				}
			}

			if (isLowPoint)
			{
				retval->push_back(std::pair<int, int>{ i,j });
			}
		}
	}
	return retval;
}

int HeightMap::sumPoints(std::vector<std::pair<int, int>>* points)
{
	int sum = 0;

	for (int i = 0; i < points->size(); i++)
	{
		std::pair<int, int> point = points->at(i);
		sum += heightArray->at(point.first)->at(point.second);
	}
	return sum;
}

std::vector<std::vector<std::pair<int,int>>* > * HeightMap::getBasins()
{
	std::vector<std::pair<int, int>>* lowPoints = getLowPoints();
	std::vector<std::vector<std::pair<int, int>>*>* basins = new std::vector<std::vector<std::pair<int, int>>*>();
	
	for (int index = 0; index < lowPoints->size(); index++)
	{
		std::pair<int, int> lowPoint = lowPoints->at(index);
		std::vector<std::pair<int, int>>* basin = new std::vector<std::pair<int, int>>();
		std::vector<std::pair<int, int>>* pointsUnderConsideration = new std::vector<std::pair<int, int>>();
		pointsUnderConsideration->push_back(lowPoint);
		basin->push_back(lowPoint);
		while (!pointsUnderConsideration->empty())
		{
			std::pair<int, int> pointUnderConsideration = pointsUnderConsideration->at(0);
			pointsUnderConsideration->erase(pointsUnderConsideration->begin(), pointsUnderConsideration->begin() + 1);

			int i = pointUnderConsideration.first;
			int j = pointUnderConsideration.second;

			int pointUnderConsiderationHeight = heightArray->at(i)->at(j);

			int heightCheckUpper = i - (i != 0);
			int heightCheckLower = i + (i != height - 1);
			int widthCheckLeft = j - (j != 0);
			int widthCheckRight = j + (j != width - 1);

			for (int a = heightCheckUpper; a <= heightCheckLower; a++)
			{
				if (a == i)
				{
					continue;
				}

				int neighbourPointHeight = heightArray->at(a)->at(j);
				if (neighbourPointHeight >= pointUnderConsiderationHeight
				  && neighbourPointHeight != 9)
				{
					std::pair<int, int> neighbourPoint{ a, j };
					if (std::find(basin->begin(), basin->end(), neighbourPoint) == basin->end())
					{
						basin->push_back(neighbourPoint);
						pointsUnderConsideration->push_back(neighbourPoint);
					}
				}
			}

			for (int a = widthCheckLeft; a <= widthCheckRight; a++)
			{
				if (a == j)
				{
					continue;
				}

				int neighbourPointHeight = heightArray->at(i)->at(a);
				if (neighbourPointHeight >= pointUnderConsiderationHeight
					&& neighbourPointHeight != 9)
				{
					std::pair<int, int> neighbourPoint{ i, a };
					if (std::find(basin->begin(), basin->end(), neighbourPoint) == basin->end())
					{
						basin->push_back(neighbourPoint);
						pointsUnderConsideration->push_back(neighbourPoint);
					}
				}
			}
		}
		if (!basin->empty())
		{
			basins->push_back(basin);
		}
	}
	return basins;
}