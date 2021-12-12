#include "Day8.h"

void day8()
{
	day8_1_soln();
	std::cout << '\n' << '\n';
	day8_2_soln();
}

void day8_1_soln()
{
	std::vector<SegmentDisplayResult*>* results = parseFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day8\\digitDisplay.txt");

	int count = 0;
	for (int i = 0; i < results->size(); i++)
	{
		int size = results->at(i)->digitCodesDisplayed.size();
		for (int j = 0; j < size; j++)
		{
			if (isAUniqueLength(results->at(i)->digitCodesDisplayed.at(j)))
			{
				count++;
			}
		}
	}
	std::cout << count;
}

void day8_2_soln()
{
	std::vector<SegmentDisplayResult*>* results = parseFromFile("C:\\Users\\eddie\\Documents\\AdventOfCode\\AdventOfCode\\Resources\\Day8\\digitDisplay.txt");
	
	int sum = 0;
	for (int i = 0; i < results->size(); i++)
	{
		sum += results->at(i)->solve();
	}
	std::cout << sum;
}

std::vector<SegmentDisplayResult*>* parseFromFile(std::string filePath)
{
	std::vector<SegmentDisplayResult*>* retval = new std::vector<SegmentDisplayResult*>();

	std::ifstream inFile;
	inFile.open(filePath);

	if (inFile.fail())
	{
		std::cout << "ERROR: File not found" << '\n';
		return retval;
	}

	std::string line = "";
	while (std::getline(inFile, line))
	{
		retval->push_back(new SegmentDisplayResult(line));
	}
	return retval;
}

SegmentDisplayResult::SegmentDisplayResult(std::string line)
{
	parse(line);
}
void SegmentDisplayResult::parse(std::string line)
{
	//First find the index of the "|" and split the line
	int pipeIndex = line.find_first_of('|');
	std::string numberWirings = line.substr(0, pipeIndex);
	std::string digitCodesDisplayed = line.substr(pipeIndex + 1);

	this->numberWirings = *parseDelimitedStringToVector(numberWirings, ' ');
	this->digitCodesDisplayed = *parseDelimitedStringToVector(digitCodesDisplayed, ' ');

	initializeAnagramMap();
}

void SegmentDisplayResult::initializeAnagramMap()
{
	for (int i = 0; i < digitCodesDisplayed.size(); i++)
	{
		for (int j = 0; j < numberWirings.size(); j++)
		{
			if (areAnagrams(digitCodesDisplayed.at(i), numberWirings.at(j)))
			{
				anagramMap.insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{digitCodesDisplayed.at(i), numberWirings.at(j)} });
			}
		}
	}
}

int SegmentDisplayResult::solve()
{
	std::string solve_0;
	std::string solve_1;
	std::string solve_2;
	std::string solve_3;
	std::string solve_4;
	std::string solve_5;
	std::string solve_6;
	std::string solve_7;
	std::string solve_8;
	std::string solve_9;

	solve_1 = getWiringsForLength(CONNECTIONS_1)->at(0);
	solve_4 = getWiringsForLength(CONNECTIONS_4)->at(0);
	solve_7 = getWiringsForLength(CONNECTIONS_7)->at(0);
	solve_8 = getWiringsForLength(CONNECTIONS_8)->at(0);

	char sevenMinusOne = getFromFirstWhereNotInSecond(solve_7, solve_1)->at(0);
	std::string fourMinusOne = getFromFirstWhereNotInSecondStr(solve_4, solve_1);

	//Now work out what the 5 character numbers are
	std::vector<std::string>* wiringsOfLength5 = getWiringsForLength(5);
	for (int i = 0; i < wiringsOfLength5->size(); i++)
	{
		std::string wiringOfLength5 = wiringsOfLength5->at(i);

		if (getFromFirstWhereNotInSecondStr(fourMinusOne, wiringOfLength5) != "") //It must be 3 or 2
		{
			if (getFromFirstWhereNotInSecondStr(solve_1, wiringOfLength5).length() == 1) //it must be 2
			{
				solve_2 = wiringOfLength5;
			}
			else
			{
				solve_3 = wiringOfLength5;
			}
		}
		else //it must be 5
		{
			solve_5 = wiringOfLength5;
		}
	}

	//Now only 0, 6 & 9 remain to be solved!
	std::vector<std::string>* wiringsOfLength6 = getWiringsForLength(6);
	for (int i = 0; i < wiringsOfLength6->size(); i++)
	{
		std::string wiringOfLength6 = wiringsOfLength6->at(i);
		if (getFromFirstWhereNotInSecondStr(solve_1, wiringOfLength6).length() == 1) //it must be 6
		{
			solve_6 = wiringOfLength6;
		}
		else //It must be 0 or 9
		{
			if (getFromFirstWhereNotInSecondStr(fourMinusOne, wiringOfLength6).length() == 0)
			{
				solve_9 = wiringOfLength6;
			}
			else
			{
				solve_0 = wiringOfLength6;
			}
		}
	}

	//Now that we know all the wirings, we just need to find out what the number on the display is!
	//Put the wirings in a map...
	std::map<std::string, std::string>* wiresMap = new std::map<std::string, std::string>();
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_0, "0"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_1, "1"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_2, "2"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_3, "3"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_4, "4"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_5, "5"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_6, "6"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_7, "7"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_8, "8"} });
	wiresMap->insert(std::initializer_list<std::pair<const std::string, std::string>>{ std::pair<const std::string, std::string>{solve_9, "9"} });

	std::string displayAsNumberStr = "";
	for (int i = 0; i < digitCodesDisplayed.size(); i++)
	{
		std::string digitCodesMapped = anagramMap.find(digitCodesDisplayed.at(i))->second;
		displayAsNumberStr += wiresMap->find(digitCodesMapped)->second;
	}
	//std::cout << displayAsNumberStr << '\n';
	return std::stoi(displayAsNumberStr);
}

std::vector<std::string>* SegmentDisplayResult::getWiringsForLength(int length)
{
	std::vector<std::string>* retval = new std::vector<std::string>();
	for (int i = 0; i < numberWirings.size(); i++)
	{
		if (numberWirings.at(i).length() == length)
		{
			retval->push_back(numberWirings.at(i));
		}
	}
	return retval;
}

bool isAUniqueLength(std::string digitCodeStr)
{
	int digitLength = digitCodeStr.length();
	return
		digitLength == CONNECTIONS_1
		|| digitLength == CONNECTIONS_4
		|| digitLength == CONNECTIONS_7
		|| digitLength == CONNECTIONS_8;
}