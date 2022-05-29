#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "global.h"

using namespace std;



int main(){
    srand(time(0));
    int gameStepCounter = 0;
    question gameSet[15]; //zestaw pytan do calej gry
    for(int i = 0;i<15;i++){ //losowanie zestawu 15 pytan
        gameSet[i] = getQuestions(i+1);
    }
    return 0;
}