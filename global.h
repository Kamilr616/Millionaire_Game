#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>
#include <fstream>
#include <iterator>
#include "question.cpp"
#include "generateSet.cpp"
using namespace std;

question questionFromLine(string qLine);
question getQuestions(int stepCounter);





#endif // GLOBAL_H
