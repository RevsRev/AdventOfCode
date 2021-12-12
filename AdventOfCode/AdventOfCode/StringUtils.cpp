#include "StringUtils.h"

std::vector<std::string>* parseDelimitedStringToVector(std::string str, char delimiter)
{
	std::vector<std::string>* retval = new std::vector<std::string>();

	while (str.length() > 0)
	{
		if (str.find_first_of(delimiter) == 0)
		{
			str.erase(0,1);
		}

		std::string tok = "";
		while (str.length() > 0
		  && str.find_first_of(delimiter) != 0)
		{
			tok += str.at(0);
			str.erase(0,1);
		}

		if (tok != "")
		{
			retval->push_back(tok);
		}
	}
	return retval;
}

std::vector<char>* getFromFirstWhereNotInSecond(std::string first, std::string second)
{
	std::vector<char>* retval = new std::vector<char>();
	for (int i = 0; i < first.length(); i++)
	{
		char letter = first.at(i);
		if (second.find_first_of(letter) == std::string::npos
		  && std::find(retval->begin(), retval->end(), letter) == retval->end())
		{
			retval->push_back(letter);
		}
	}
	return retval;
}

std::string getFromFirstWhereNotInSecondStr(std::string first, std::string second)
{
	std::string retval = "";

	std::vector<char>* inFirstNotSecond = getFromFirstWhereNotInSecond(first, second);
	for (int i = 0; i < inFirstNotSecond->size(); i++)
	{
		retval += inFirstNotSecond->at(i);
	}
	return retval;
}

bool areAnagrams(std::string first, std::string second)
{
	if (first.length() != second.length())
	{
		return false;
	}

	while (first.length() > 0)
	{
		char letter = first.at(0);
		if (second.find_first_of(letter) != std::string::npos)
		{
			int index = second.find_first_of(letter);
			first.erase(0, 1);
			second.erase(index, 1);
		}
		else
		{
			return false;
		}
	}
	return true;
}