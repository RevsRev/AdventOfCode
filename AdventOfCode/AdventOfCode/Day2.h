#pragma once

#include <iostream>
#include <string>
#include <vector>

extern const std::string UP;
extern const std::string DOWN;
extern const std::string FORWARD;
extern const std::vector<std::string> commands;
extern const std::vector<std::string> commands_test;
extern void day2();
extern void day2_1_soln();
extern void day2_1_soln(std::vector<std::string> commands);
extern void parseCommand2_1(std::string& command, std::vector<int> &position);
extern int stripCommand(std::string& command, const std::string& prefixToStrip);
extern void day2_2_soln();
extern void day2_2_soln(std::vector<std::string> commands);
extern void parseCommand2_2(std::string& command, std::vector<int>& position);