#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>


using namespace std;


//  V   zakomentwoac w przypadku kompilacji na linux
//#define WINDOWS  

void clear_screen()
{
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

#endif // GLOBAL_HPP
