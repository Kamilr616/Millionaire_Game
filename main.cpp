#include "global.hpp"
#include "question.hpp"

#include "stage.hpp"
#include "question.cpp"
#include "stage.cpp"

using namespace std;

int main()
{

    int i, option;
    bool lifelines[3] = {false}; // lifelines[0] - 50/50, [1] - telefon do przyjaciela, [2] - pytanie do publicznosci
    i = 0;
    option = 1;

    srand(time(0));

    question gameSet[15]; // zestaw pytan do calej gry

    Stage game; //  etap gry

    while(option)
    {
        system("cls"); // cmd terminal clear
        cout << "Gra milionerzy " << endl
             << "1. Nowa gra" << endl
             << "0. Zakoncz" << endl;

        cin >> option;

        for (i = 0; i < 15; i++) // losowanie zestawu 15 pytan
        {
            gameSet[i] = gameSet[i].getQuestions(i + 1);
        }

        switch (option)
        {
        case 1:
            while (true)
            {
                system("cls"); // cmd terminal clear

                if (game.getGameStage() >= 15)
                {
                    cout << "Jestes milionerem !!!" << endl
                         << "Koniec gry" << endl
                         << "Wynik > " << game.end() << " zL" << endl;
                    system("PAUSE");
                    break;
                }

                game.show();

                if (((gameSet[game.getGameStage()].askQuestion(lifelines)) == true))
                {
                    system("PAUSE");
                    game.up();
                }
                else
                {
                    cout << "Koniec gry!" << endl
                         << "Twoj wynik > " << game.end() << " zL" << endl;
                    system("PAUSE");
                    break;
                }
            }
            break;
        case 0:
            option = 0;
            break;
        default:
            break;
        }
        
    }

    return 0;
}