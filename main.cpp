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

    
    while(1)
    {

        system("cls"); // cmd terminal clear

        if(game.getGameStage() >= 15)
        {
            cout << "Jestes milionerem !!!" << endl
                 << "Koniec gry" << endl
                 << "Wynik > " << game.end() << " zL" << endl;
            system("PAUSE");
            break;
        }

        game.show();

        if (((gameSet[game.getGameStage()].askQuestion()) == true))
        {
            system("PAUSE");
            game.up();
        }
        else
        {
            cout << "Twoj wynik > " << game.end() << " zL" << endl;
            system("PAUSE");
            break;
        }

    }
    return 0;
}