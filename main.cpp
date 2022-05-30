#include "global.hpp"
#include "question.hpp"

#include "stage.hpp"
#include "question.cpp"
#include "stage.cpp"

using namespace std;


int main()
{

    int i, option;

    i = 0;
    option = 1;

    srand(time(0));

    question gameSet[15]; //zestaw pytan do calej gry

    Stage game;

    while(option > 0)
    {

        for (i = 0; i < 15; i++) // losowanie zestawu 15 pytan
        {
            gameSet[i] = gameSet[i].getQuestions(i+1);
        }

        system("cls"); // cmd terminal clear
        gameSet[game.getGameStage()].askQuestion();

        cout << "0.Zakoncz" << endl;
        cin >> option;
    }
    return 0;
}