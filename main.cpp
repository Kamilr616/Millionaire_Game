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
                << "0 > Poddaj sie" << endl
                << "Odpowiedz >> ";

            cin >> userAns;

            if(userAns == gameSet[i].getCorr())
            {
                cout << "Gratulacje! Poprawna odpowiedz to ";
                
                    switch (userAns)
                    {
                    case 1:
                        cout << gameSet[i].getAns1();
                        break;
                    case 2:
                        cout << gameSet[i].getAns2();
                        break;
                    case 3:
                        cout << gameSet[i].getAns3();
                        break;
                    case 4:
                        cout << gameSet[i].getAns4();
                        break;
                    case 0:
                        option = -1;
                        break;
                    default:
                        break;
                    }
       
                    cout << endl << "Nastepny etap > " << (i + 2) << endl;
            }
            else
            {
                system("cls"); // cmd terminal clear
                cout << "GAME OVER" << endl;
                option = -1;
                break;
            }
            system("PAUSE");

        }

        cout << "Twoj wynik > " << (i + 1) << endl
             << "Kontynuowac? 0. Zakoncz" << endl;
        cin >> option;
    }


    return 0;
}