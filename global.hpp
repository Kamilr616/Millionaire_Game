#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <limits>
#include <stdexcept>
#include <vector>


using namespace std;


inline void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#endif // GLOBAL_HPP
