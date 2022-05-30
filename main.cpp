#include "global.hpp"

using namespace std;


int main()
{

    int gameStepCounter = 0;
    
    srand(time(0));

    question gameSet[15]; //zestaw pytan do calej gry

    for (int i = 0; i < 15; i++) // losowanie zestawu 15 pytan
    {
        gameSet[i] = getQuestions(i+1);
    }


    return 0;
}