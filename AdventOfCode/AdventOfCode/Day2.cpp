#include "Day2.h"


void day2()
{
	day2_1_soln();
	std::cout << '\n' << '\n';
	day2_2_soln();
}

void day2_1_soln()
{
	std::cout << "Test: ";
	day2_1_soln(commands_test);
	std::cout << '\n' << "Real: ";
	day2_1_soln(commands);
}

void day2_1_soln(std::vector<std::string> commands)
{
	std::vector<int> position{ 0,0 };
	for (int i = 0; i < commands.size(); i++)
	{
		std::string command = commands.at(i);
		parseCommand2_1(command, position);
	}
	std::cout << "Horizontal: " << position.at(0) << ", Vertial: " << position.at(1);
	std::cout << '\n' << "The product of these is: " << position.at(0) * position.at(1);
}

void parseCommand2_1(std::string& command, std::vector<int> &position)
{
	if (command.find(UP) != std::string::npos)
	{
		int up = stripCommand(command, UP);
		position.at(1) -= up;
	}
	else if (command.find(DOWN) != std::string::npos)
	{
		int down = stripCommand(command, DOWN);
		position.at(1) += down;
	}
	else if (command.find(FORWARD) != std::string::npos)
	{
		int forward = stripCommand(command, FORWARD);
		position.at(0) += forward;
	}
	else
	{
		std::cout << "ERROR: Unidentified command: " << command << '\n';
	}
}

int stripCommand(std::string& command, const std::string& prefixToStrip)
{
	size_t index = command.find(prefixToStrip);
	std::string commandValue = command.substr(index + prefixToStrip.length(), command.length() - prefixToStrip.length());
	return std::stoi(commandValue);
}

void day2_2_soln()
{
	std::cout << "Test: ";
	day2_2_soln(commands_test);
	std::cout << '\n' << "Real: ";
	day2_2_soln(commands);
}
void day2_2_soln(std::vector<std::string> commands)
{
	std::vector<int> position{ 0,0,0}; //x,y, aim
	for (int i = 0; i < commands.size(); i++)
	{
		std::string command = commands.at(i);
		parseCommand2_2(command, position);
	}
	std::cout << "Horizontal: " << position.at(0) << ", Vertial: " << position.at(1);
	std::cout << '\n' << "The product of these is: " << position.at(0) * position.at(1);
}

void parseCommand2_2(std::string& command, std::vector<int>& position)
{
	if (command.find(UP) != std::string::npos)
	{
		int up = stripCommand(command, UP);
		position.at(2) -= up;
	}
	else if (command.find(DOWN) != std::string::npos)
	{
		int down = stripCommand(command, DOWN);
		position.at(2) += down;
	}
	else if (command.find(FORWARD) != std::string::npos)
	{
		int forward = stripCommand(command, FORWARD);
		position.at(0) += forward;
		position.at(1) += forward * position.at(2);
	}
	else
	{
		std::cout << "ERROR: Unidentified command: " << command << '\n';
	}
}

const std::string UP{ "up " };
const std::string DOWN{ "down " };
const std::string FORWARD{ "forward " };

const std::vector<std::string> commands
{
	"forward 3",
	"down 7",
	"forward 8",
	"down 9",
	"forward 3",
	"down 5",
	"down 9",
	"down 6",
	"forward 1",
	"forward 8",
	"forward 9",
	"forward 3",
	"down 7",
	"down 8",
	"up 3",
	"down 5",
	"down 8",
	"down 9",
	"forward 5",
	"forward 6",
	"down 2",
	"forward 1",
	"forward 3",
	"down 9",
	"up 6",
	"up 2",
	"down 7",
	"down 9",
	"forward 2",
	"down 9",
	"up 3",
	"forward 5",
	"up 9",
	"up 9",
	"forward 4",
	"down 6",
	"up 7",
	"up 8",
	"up 6",
	"up 2",
	"down 7",
	"forward 9",
	"down 4",
	"forward 2",
	"forward 1",
	"up 7",
	"down 2",
	"down 8",
	"down 8",
	"down 2",
	"down 7",
	"down 3",
	"up 4",
	"down 7",
	"down 1",
	"down 7",
	"down 7",
	"forward 8",
	"forward 1",
	"forward 5",
	"forward 1",
	"forward 9",
	"forward 3",
	"forward 5",
	"down 3",
	"forward 9",
	"down 4",
	"down 2",
	"forward 5",
	"down 4",
	"down 4",
	"down 4",
	"down 9",
	"down 6",
	"down 5",
	"forward 2",
	"down 2",
	"down 8",
	"down 8",
	"down 7",
	"down 2",
	"down 8",
	"down 6",
	"down 4",
	"down 7",
	"up 8",
	"up 7",
	"up 6",
	"down 4",
	"down 2",
	"up 4",
	"up 8",
	"up 4",
	"down 4",
	"down 3",
	"forward 7",
	"forward 8",
	"up 1",
	"up 1",
	"up 7",
	"forward 2",
	"down 2",
	"forward 7",
	"forward 7",
	"forward 7",
	"down 2",
	"down 2",
	"forward 5",
	"down 3",
	"forward 3",
	"down 6",
	"down 9",
	"down 4",
	"down 1",
	"forward 2",
	"forward 2",
	"down 8",
	"down 9",
	"up 3",
	"forward 8",
	"down 7",
	"forward 6",
	"forward 6",
	"down 9",
	"up 2",
	"up 9",
	"down 2",
	"down 8",
	"up 2",
	"forward 6",
	"down 5",
	"up 9",
	"forward 6",
	"down 3",
	"down 9",
	"forward 8",
	"forward 8",
	"forward 1",
	"forward 6",
	"down 7",
	"forward 3",
	"forward 5",
	"forward 6",
	"down 1",
	"down 1",
	"forward 3",
	"forward 8",
	"forward 8",
	"up 5",
	"down 6",
	"up 5",
	"down 1",
	"up 3",
	"down 6",
	"forward 1",
	"up 3",
	"up 4",
	"down 8",
	"down 2",
	"up 2",
	"forward 1",
	"forward 2",
	"forward 6",
	"up 2",
	"down 3",
	"up 5",
	"down 5",
	"down 7",
	"up 6",
	"up 6",
	"down 8",
	"forward 7",
	"forward 2",
	"forward 3",
	"up 5",
	"down 5",
	"down 6",
	"down 4",
	"forward 8",
	"up 1",
	"forward 5",
	"up 1",
	"forward 4",
	"forward 3",
	"forward 4",
	"down 2",
	"up 5",
	"up 4",
	"down 5",
	"forward 1",
	"forward 8",
	"down 7",
	"down 1",
	"down 7",
	"forward 6",
	"down 4",
	"down 6",
	"forward 6",
	"down 8",
	"forward 7",
	"down 4",
	"down 8",
	"up 7",
	"down 6",
	"down 2",
	"up 8",
	"down 7",
	"down 8",
	"down 6",
	"down 3",
	"up 1",
	"down 7",
	"forward 1",
	"down 3",
	"down 5",
	"down 9",
	"down 3",
	"forward 1",
	"forward 4",
	"forward 2",
	"down 8",
	"forward 7",
	"down 3",
	"down 7",
	"forward 7",
	"down 4",
	"down 5",
	"down 1",
	"forward 2",
	"down 7",
	"forward 3",
	"forward 4",
	"down 8",
	"up 6",
	"down 4",
	"up 5",
	"forward 5",
	"forward 7",
	"up 8",
	"forward 6",
	"up 3",
	"forward 9",
	"up 9",
	"down 1",
	"down 2",
	"forward 6",
	"down 5",
	"forward 6",
	"down 7",
	"forward 9",
	"down 2",
	"up 5",
	"down 2",
	"forward 3",
	"up 7",
	"forward 3",
	"down 4",
	"forward 7",
	"forward 8",
	"down 5",
	"up 7",
	"up 8",
	"forward 7",
	"down 4",
	"forward 9",
	"forward 6",
	"down 2",
	"forward 3",
	"up 8",
	"up 4",
	"forward 2",
	"forward 4",
	"forward 1",
	"down 6",
	"forward 1",
	"down 9",
	"forward 2",
	"up 5",
	"down 2",
	"down 5",
	"down 5",
	"down 2",
	"down 9",
	"down 4",
	"forward 5",
	"down 5",
	"up 1",
	"forward 4",
	"down 6",
	"down 5",
	"up 8",
	"up 4",
	"down 8",
	"forward 4",
	"down 8",
	"forward 4",
	"down 2",
	"down 8",
	"forward 3",
	"forward 7",
	"down 1",
	"forward 3",
	"forward 7",
	"forward 1",
	"down 4",
	"forward 2",
	"down 3",
	"down 4",
	"forward 1",
	"up 6",
	"forward 8",
	"down 5",
	"up 6",
	"up 3",
	"forward 7",
	"down 3",
	"forward 4",
	"forward 9",
	"forward 2",
	"up 2",
	"up 7",
	"forward 1",
	"up 8",
	"down 6",
	"up 5",
	"down 3",
	"up 7",
	"down 4",
	"up 7",
	"down 8",
	"down 7",
	"forward 5",
	"up 7",
	"down 1",
	"up 9",
	"down 2",
	"down 8",
	"down 5",
	"forward 4",
	"down 3",
	"up 4",
	"down 2",
	"forward 6",
	"down 2",
	"forward 9",
	"up 9",
	"up 8",
	"forward 3",
	"forward 7",
	"forward 7",
	"up 4",
	"up 3",
	"up 4",
	"forward 1",
	"down 2",
	"up 6",
	"down 2",
	"down 4",
	"up 3",
	"down 8",
	"down 9",
	"down 4",
	"forward 6",
	"down 5",
	"down 5",
	"forward 7",
	"down 2",
	"forward 8",
	"up 2",
	"up 7",
	"down 5",
	"down 7",
	"up 9",
	"up 4",
	"up 5",
	"down 4",
	"down 8",
	"down 9",
	"down 7",
	"down 1",
	"down 1",
	"up 7",
	"up 8",
	"down 5",
	"forward 2",
	"up 3",
	"down 2",
	"down 9",
	"down 4",
	"forward 1",
	"forward 1",
	"up 4",
	"down 9",
	"up 7",
	"forward 7",
	"up 8",
	"up 4",
	"down 2",
	"down 1",
	"forward 2",
	"up 4",
	"down 3",
	"up 7",
	"down 7",
	"down 6",
	"down 4",
	"up 3",
	"down 7",
	"forward 5",
	"down 6",
	"down 9",
	"down 3",
	"forward 1",
	"down 6",
	"forward 3",
	"down 5",
	"up 1",
	"forward 5",
	"forward 4",
	"forward 8",
	"forward 1",
	"up 4",
	"down 2",
	"down 7",
	"down 9",
	"up 4",
	"up 6",
	"forward 8",
	"up 4",
	"down 8",
	"forward 7",
	"forward 1",
	"down 7",
	"forward 9",
	"forward 1",
	"forward 7",
	"forward 9",
	"down 3",
	"forward 4",
	"down 3",
	"down 3",
	"down 3",
	"down 1",
	"down 5",
	"forward 1",
	"forward 7",
	"up 5",
	"forward 5",
	"forward 4",
	"forward 7",
	"down 7",
	"up 5",
	"forward 1",
	"forward 8",
	"down 3",
	"up 6",
	"down 7",
	"forward 6",
	"down 8",
	"forward 6",
	"up 4",
	"down 9",
	"up 1",
	"forward 4",
	"forward 8",
	"down 5",
	"forward 7",
	"up 9",
	"forward 2",
	"up 2",
	"forward 7",
	"down 3",
	"forward 2",
	"down 7",
	"down 1",
	"forward 9",
	"forward 3",
	"up 5",
	"forward 7",
	"up 4",
	"forward 2",
	"down 3",
	"down 2",
	"down 8",
	"forward 7",
	"down 8",
	"down 3",
	"forward 9",
	"forward 9",
	"forward 5",
	"up 8",
	"forward 9",
	"up 2",
	"forward 2",
	"up 4",
	"forward 2",
	"forward 1",
	"forward 7",
	"forward 6",
	"down 5",
	"forward 5",
	"forward 1",
	"forward 7",
	"forward 4",
	"down 5",
	"down 9",
	"down 8",
	"forward 5",
	"up 5",
	"up 1",
	"down 8",
	"down 9",
	"forward 1",
	"down 5",
	"forward 6",
	"down 1",
	"down 7",
	"down 7",
	"down 4",
	"forward 3",
	"down 5",
	"down 8",
	"forward 2",
	"down 4",
	"forward 3",
	"down 1",
	"up 5",
	"down 8",
	"forward 9",
	"up 6",
	"up 4",
	"down 6",
	"down 9",
	"forward 2",
	"forward 5",
	"down 3",
	"forward 2",
	"down 5",
	"forward 1",
	"forward 4",
	"down 6",
	"down 4",
	"up 2",
	"down 9",
	"forward 2",
	"up 8",
	"down 4",
	"forward 7",
	"down 5",
	"forward 8",
	"down 1",
	"forward 5",
	"down 7",
	"up 5",
	"down 7",
	"down 4",
	"forward 3",
	"down 1",
	"forward 7",
	"forward 9",
	"up 9",
	"forward 5",
	"forward 8",
	"up 8",
	"forward 6",
	"down 5",
	"down 8",
	"forward 9",
	"forward 3",
	"down 3",
	"forward 9",
	"forward 7",
	"forward 6",
	"forward 1",
	"up 2",
	"forward 8",
	"down 9",
	"down 5",
	"down 5",
	"down 4",
	"forward 7",
	"down 8",
	"down 7",
	"forward 8",
	"forward 2",
	"down 5",
	"forward 2",
	"forward 3",
	"down 6",
	"down 8",
	"up 8",
	"forward 7",
	"down 7",
	"up 7",
	"forward 5",
	"up 6",
	"forward 7",
	"up 6",
	"forward 8",
	"forward 5",
	"up 6",
	"forward 1",
	"down 5",
	"forward 1",
	"up 5",
	"down 1",
	"forward 6",
	"forward 3",
	"up 2",
	"forward 9",
	"forward 8",
	"down 9",
	"forward 7",
	"forward 7",
	"forward 8",
	"up 9",
	"down 8",
	"up 1",
	"down 4",
	"forward 2",
	"forward 7",
	"down 1",
	"up 7",
	"down 5",
	"forward 2",
	"down 4",
	"down 8",
	"forward 6",
	"down 3",
	"forward 8",
	"up 6",
	"forward 5",
	"forward 7",
	"down 5",
	"down 1",
	"down 7",
	"down 7",
	"up 8",
	"down 5",
	"forward 4",
	"down 5",
	"down 7",
	"down 2",
	"up 8",
	"forward 6",
	"up 1",
	"down 3",
	"forward 9",
	"up 1",
	"down 7",
	"forward 2",
	"down 6",
	"forward 6",
	"up 3",
	"up 9",
	"up 2",
	"forward 4",
	"forward 4",
	"down 4",
	"down 4",
	"down 2",
	"down 5",
	"forward 7",
	"forward 6",
	"forward 9",
	"down 9",
	"forward 6",
	"up 1",
	"down 2",
	"down 4",
	"down 7",
	"down 5",
	"down 4",
	"up 2",
	"up 8",
	"down 6",
	"forward 2",
	"up 7",
	"down 2",
	"up 5",
	"down 8",
	"forward 3",
	"up 2",
	"forward 3",
	"forward 5",
	"forward 9",
	"forward 2",
	"forward 8",
	"forward 1",
	"down 5",
	"up 6",
	"forward 9",
	"forward 4",
	"up 8",
	"down 8",
	"up 2",
	"down 9",
	"down 3",
	"down 5",
	"up 4",
	"forward 2",
	"down 5",
	"forward 6",
	"down 6",
	"forward 2",
	"forward 7",
	"forward 6",
	"forward 1",
	"down 7",
	"forward 8",
	"up 2",
	"forward 5",
	"forward 5",
	"up 3",
	"forward 2",
	"forward 3",
	"forward 8",
	"forward 4",
	"down 1",
	"down 9",
	"up 5",
	"down 5",
	"forward 1",
	"down 8",
	"up 3",
	"down 9",
	"forward 5",
	"forward 2",
	"forward 2",
	"up 1",
	"forward 1",
	"down 5",
	"forward 4",
	"up 4",
	"up 3",
	"up 3",
	"down 4",
	"down 5",
	"down 1",
	"forward 8",
	"down 4",
	"up 7",
	"down 6",
	"forward 5",
	"forward 4",
	"forward 8",
	"forward 8",
	"up 3",
	"forward 7",
	"down 4",
	"forward 8",
	"forward 4",
	"forward 6",
	"down 8",
	"down 6",
	"down 1",
	"forward 4",
	"down 8",
	"down 6",
	"forward 2",
	"down 8",
	"up 7",
	"down 2",
	"forward 5",
	"down 4",
	"down 7",
	"down 8",
	"forward 5",
	"down 4",
	"down 2",
	"down 7",
	"down 4",
	"forward 7",
	"forward 3",
	"up 4",
	"down 7",
	"down 9",
	"up 4",
	"up 5",
	"down 7",
	"up 5",
	"down 3",
	"down 5",
	"forward 8",
	"up 1",
	"up 9",
	"forward 9",
	"forward 7",
	"down 2",
	"up 1",
	"up 7",
	"down 3",
	"forward 3",
	"up 6",
	"forward 1",
	"forward 2",
	"down 4",
	"down 3",
	"forward 4",
	"forward 7",
	"forward 9",
	"down 8",
	"down 6",
	"forward 1",
	"forward 3",
	"forward 2",
	"up 3",
	"down 6",
	"down 7",
	"up 8",
	"down 5",
	"up 6",
	"down 8",
	"forward 4",
	"up 3",
	"forward 3",
	"forward 4",
	"down 5",
	"up 5",
	"down 4",
	"down 5",
	"down 5",
	"forward 3",
	"up 9",
	"down 8",
	"down 2",
	"down 7",
	"down 4",
	"down 3",
	"up 2",
	"forward 6",
	"down 4",
	"down 1",
	"down 4",
	"forward 1",
	"forward 8",
	"down 3",
	"down 7",
	"down 3",
	"forward 1",
	"down 9",
	"down 7",
	"down 3",
	"down 3",
	"down 6",
	"down 8",
	"down 2",
	"down 5",
	"up 1",
	"up 7",
	"forward 9",
	"forward 6",
	"forward 7",
	"forward 8",
	"up 7",
	"down 9",
	"down 4",
	"down 7",
	"forward 2",
	"forward 4",
	"forward 1",
	"forward 4",
	"forward 3",
	"forward 8",
	"down 5",
	"forward 8",
	"up 4",
	"up 9",
	"forward 3",
	"down 7",
	"forward 9",
	"down 2",
	"forward 5",
	"up 7",
	"down 4",
	"down 3",
	"down 5",
	"down 4",
	"forward 9",
	"forward 5",
	"forward 6",
	"forward 6",
	"down 2",
	"down 7",
	"forward 4",
	"up 5",
	"down 8",
	"down 9",
	"forward 5",
	"down 8",
	"forward 9",
	"up 6",
	"forward 8",
	"forward 7",
	"up 7",
	"down 9",
	"forward 5",
	"down 9",
	"forward 7",
	"down 5",
	"down 7",
	"forward 9",
	"forward 4",
	"up 1",
	"up 9",
	"forward 7",
	"up 5",
	"up 2",
	"down 6",
	"forward 7",
	"down 2",
	"forward 6",
	"forward 7",
	"down 4",
	"up 3",
	"up 9",
	"forward 4",
	"forward 6",
	"forward 3",
	"up 6",
	"down 5",
	"up 2",
	"forward 3",
	"down 5",
	"forward 1",
	"up 7",
	"down 8",
	"up 4",
	"forward 9",
	"forward 6",
	"down 7",
	"forward 4",
	"down 9",
	"down 8",
	"down 7",
	"forward 7",
	"down 5",
	"forward 3",
	"up 5",
	"forward 9",
	"forward 7",
	"forward 3",
	"down 5",
	"forward 8",
	"down 3",
	"forward 1",
	"down 3",
	"down 3",
	"forward 2",
	"down 4",
	"forward 7",
	"up 1",
	"down 6",
	"up 3",
	"forward 8",
	"down 6",
	"forward 6",
	"down 5",
	"down 4",
	"forward 3",
	"up 1",
	"forward 5",
	"forward 5",
	"forward 2",
	"up 9",
	"forward 3",
	"down 5",
	"up 3",
	"up 4",
	"down 7",
	"down 4",
	"up 3",
	"up 3",
	"forward 2",
	"up 2",
	"forward 8",
	"down 9",
	"down 1",
	"up 8",
	"down 2",
	"up 4",
	"forward 9",
	"up 1",
	"down 8",
	"forward 3",
	"up 9",
	"down 7",
	"down 5",
	"down 9",
	"down 1",
	"down 2",
	"down 9",
	"down 4",
	"down 8",
	"down 8",
	"down 9",
	"down 2",
	"down 6",
	"down 9",
	"forward 8"
};
const std::vector<std::string> commands_test
{
	"forward 5",
	"down 5",
	"forward 8",
	"up 3",
	"down 8",
	"forward 2"
};