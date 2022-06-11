#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>


using namespace std;

#define WINDOWS  //proszę zakomentwoać w przypadku kompilacji na linux

void clear_screen()
{
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

#endif // GLOBAL_HPP
