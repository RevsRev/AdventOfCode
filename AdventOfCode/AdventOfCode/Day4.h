#pragma once
#include <vector>
#include <string>
#include <iostream>

extern const std::vector<int> drawNumbers;
extern const std::vector<int> drawNumbers_test;
extern const std::vector<std::string> strArrayBoards;
extern const std::vector<std::string> strArrayBoards_test;

class BingoBoard
{
	std::vector<std::vector<std::pair<int, bool>>> *values;
	int width;
	int height;

	void parseStrArray(std::string strArray);

	std::pair<int, bool>* valAt(std::pair<int, int> position);

	bool rowIsWinner(int col);
	bool colIsWinner(int row);

public:
	BingoBoard(std::string strArray, int width, int height);
	void update(int value);
	std::vector<int>* getValsForBool(bool marked);
	int sumValsForBool(bool marked);
	bool isWinner();
};

extern void day4();
extern void day4_1_soln();
extern void day4_1_soln(const std::vector<int>* dNumbers, std::vector<BingoBoard>* boards);
extern void day4_2_soln();
extern void day4_2_soln(const std::vector<int>* dNumbers, std::vector<BingoBoard>* boards);

extern std::vector<BingoBoard>* parseBingoBoards(const std::vector<std::string>* boardsAsString, int width, int height);

