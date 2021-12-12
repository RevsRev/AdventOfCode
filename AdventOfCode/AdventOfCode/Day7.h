#pragma once

#include "Day6.h" //Already written a method to parse a file to a vector of integers
#include <math.h>
#include <algorithm>

extern void day7();
extern void day7_1_soln();
extern void day7_2_soln();

extern int findMedian(std::vector<int>* numbers);
extern int calculateOffset(std::vector<int>* numbers, int peg);//for problem 1
extern int calculateOffset2(std::vector<int>* numbers, int peg);//for problem 2