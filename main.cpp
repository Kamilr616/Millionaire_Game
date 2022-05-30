#include "global.hpp"
#include "question.hpp"
#include "question.cpp"

using namespace std;


int main()
{

    int gameStepCounter, i, option, userAns;

    gameStepCounter = 0;
    i = 0;
    option = 1;

    srand(time(0));

    question gameSet[15]; //zestaw pytan do calej gry


    while(option > 0)
    {

        for (i = 0; i < 15; i++) // losowanie zestawu 15 pytan
        {
            gameSet[i] = gameSet[i].getQuestions(i+1);

            
            system("cls");   // cmd terminal clear

            cout << "Etap : " << (i+1) << endl
                << "Pytanie: "
                << gameSet[i].getText() << endl
                << "Odpowiedzi: " << endl
                << "1 > " << gameSet[i].getAns1() << endl
                << "2 > " << gameSet[i].getAns2() << endl
                << "3 > " << gameSet[i].getAns3() << endl
                << "4 > " << gameSet[i].getAns4() << endl
                << "Odpowiedz >> ";
            cin >> userAns;
            if(userAns == gameSet[i].getCorr())
            {
                cout << "Gratulacje! Poprawna odpowiedz!";            }
            else
            {
                system("cls"); // cmd terminal clear
                cout << "GAME OVER" << endl;
                break;
            }
            system("PAUSE");

        }
        cout << "Twoj wynik >> " << (i + 1) << endl
             << "Kontynuowac? 0. Zakoncz" << endl;
        cin >> option;
    }


    return 0;
}