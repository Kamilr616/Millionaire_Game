#include "global.hpp"
#include "question.hpp"

#include "stage.hpp"
#include "question.cpp"
#include "stage.cpp"

using namespace std;

int main()
{

    int i, option,Ans;
    bool lifelines[3] = {false, false, false}; // lifelines[0] - 50/50, [1] - telefon do przyjaciela, [2] - pytanie do publicznosci
    i = 0;
    option = 1;

    srand(time(0));

    question gameSet[15]; // zestaw pytan do calej gry

    Stage game; //  etap gry

    while (option)
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

        lifelines[0] = false;
        lifelines[1] = false;
        lifelines[2] = false;

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
                Ans = (gameSet[game.getGameStage()].askQuestion(lifelines, game.getGameStage()));

                if (Ans == 1)
                {
                    system("PAUSE");
                    game.up();
                }
                else if(Ans == 2)
                {
                    cout << "Poddanie gry!" << endl
                         << "Twoj wynik > " << game.giveup() << " zL" << endl; // potrzebna nowa metoda zamiast end
                    system("PAUSE");
                    break;
                }
                
                else // np  Ans == 0
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