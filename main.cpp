#include "global.hpp"
#include "question.hpp"
#include "stage.hpp"

#include "question.cpp"
#include "stage.cpp"

using namespace std;


int main()
{
    int i, option, Ans;
    bool showAns;
    
    bool lifelines[3] = {false, false, false}; // lifelines[0] - 50/50, [1] - telefon do przyjaciela, [2] - pytanie do publicznosci

    i = 0;
    option = 1;
    showAns = false;
    
    srand(time(0));

    question gameSet[15]; // zestaw pytan do calej gry
    Stage game; //  etap gry

    while (option != 0)
    {
        clear_screen();
        cout << "Gra milionerzy " << endl
             << "1. Nowa gra" << endl
             << "2. Ustawienia programu" << endl
             << "0. Zakoncz" << endl;

        cin >> option;

        for (i = 0; i < 15; i++) // losowanie zestawu 15 pytan
            gameSet[i] = gameSet[i].getQuestions(i + 1);
        

        lifelines[0] = false;
        lifelines[1] = false;
        lifelines[2] = false;

        switch (option)
        {
        case 1:
            while (true)
            {
                clear_screen();

                if (game.getGameStage() >= 15)
                {
                    cout << "Jestes milionerem !!!" << endl
                         << "Koniec gry" << endl
                         << "Wynik > " << game.end() << " zL" << endl;

                    cin.ignore(1024, '\n');
                    cout << "Nacisnij enter aby kontynuowac...";
                    cin.get();
                    break;
                }

                Ans = (gameSet[game.getGameStage()].askQuestion(lifelines, game.getGameStage(), game.getScore(), showAns));

                if (Ans == 1)
                {
                    game.up();
                    cin.ignore(1024, '\n');
                    cout << "Nacisnij enter aby kontynuowac...";
                    cin.get();
                }
                else if(Ans == 2)
                {
                    cout << "Poddanie gry!" << endl
                         << "Twoj wynik > " << game.giveup() << " zL" << endl;
                    cin.ignore(1024, '\n');
                    cout << "Nacisnij enter aby kontynuowac...";
                    cin.get();
                    break;
                }
                
                else 
                {
                    cout << "Koniec gry!" << endl
                         << "Twoj wynik > " << game.end() << " zL" << endl;
                    cin.ignore(1024, '\n');
                    cout << "Nacisnij enter aby kontynuowac...";
                    cin.get();
                    break;
                }
            }
            break;
        case 2:
            while (option != 0)
            {
                clear_screen();
                cout << "   Ustawienia programu:" << endl;
                cout << "1. Pokaz odpowiedzi  >> " << (showAns ? "Tak" : "Nie") << endl
                     << endl
                     << "0. Cofnij" << endl
                     << "Opcja >> ";
                cin >> option;

                switch (option)
                {
                    case 1:
                        showAns = not showAns;
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
            }
            option = -1;
        }
    }
    return 0;
}