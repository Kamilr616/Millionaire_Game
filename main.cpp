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

    for (i = 0; i < 15; i++) // losowanie zestawu 15 pytan
    {
        gameSet[i] = gameSet[i].getQuestions(i + 1);
    }

    while(option > 0)
    {

        system("cls"); // cmd terminal clear
        game.show();

        if((gameSet[game.getGameStage()].askQuestion()) == true)
        {
            system("PAUSE");
            game.up();

        }
        else
        {
            cout << "Twoj wynik > " << game.end() << endl;

            cout << "0.Zakoncz" << endl;
            cin >> option;
        }
        if(game.getGameStage()>15)
        {
            cout << "Wygrałeś milion!!!" << endl;
            break;
        }

    }
    return 0;
}