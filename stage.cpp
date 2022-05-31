#include "stage.hpp"

Stage::Stage()
{
    score = 0;
    gameStage = 0;
}

Stage::~Stage() 
{
    score = 0;
    gameStage = 0;
}

int Stage::getGameStage()
{
    return gameStage;
}

int Stage::getScore()
{
    return score;
}

void Stage::up()
{
    gameStage += 1;      // nastepny etap
    switch (gameStage)   // próg gwarantowany
    {
    case 1:
        cout << "Wygrales 100 zl" << endl;
        system("PAUSE");
        score = 100;
        break;
    case 2:
        cout << "Wygrana 200 zl" << endl;
        system("PAUSE");
        score = 200;
        break;
    case 3:
        cout << "Wygrana 300 zl" << endl;
        system("PAUSE");
        score = 300;
        break;
    case 4:
        cout << "Wygrana 500 zl" << endl;
        system("PAUSE");
        score = 500;
        break;
    case 5:
        cout << "Prog gwarantowany 1000 zl" << endl;
        system("PAUSE");
        score = 1000;
        break;
    case 6:
        cout << "Wygrana 2000 zl" << endl;
        system("PAUSE");
        score = 2000;
        break;
    case 7:
        cout << "Wygrana 4000 zl" << endl;
        system("PAUSE");
        score = 4000;
        break;
    case 8:
        cout << "Wygrana 8000 zl" << endl;
        system("PAUSE");
        score = 8000;
        break;
    case 9:
        cout << "Wygrana 9000 zl" << endl;
        system("PAUSE");
        score = 9000;
        break;
    case 10:
        cout << "Prog gwarantowany 32 000 zl" << endl;
        system("PAUSE");
        score = 32000;
        break;
    case 11:
        cout << "Wygrana 64 000 zl" << endl;
        system("PAUSE");
        score = 64000;
        break;
    case 12:
        cout << "Wygrana 125 000 zl" << endl;
        system("PAUSE");
        score = 125000;
        break;
    case 13:
        cout << "Wygrana 250 000 zl" << endl;
        system("PAUSE");
        score = 250000;
        break;
    case 14:
        cout << "Wygrana 500 000 zl" << endl;
        system("PAUSE");
        score = 500000;
        break;
    case 15:
        cout << "Wygrana 1 000 000 zl" << endl;
        system("PAUSE");
        score = 1000000;
        break;
    default:
        break;
    }
}

int Stage::end()
{
    int result = score;

    if(gameStage <= 5)
        result = 0;
    if ((gameStage <= 10) && (gameStage >= 6))
        result = 1000;
    if(gameStage >= 11)
        result = 32000;
    if(gameStage >= 15)
        result = 1000000;

    gameStage = 0;
    score = 0;

    return result;
}

int Stage::giveup()
{
    int result = score;
    gameStage = 0;
    score = 0;

    return result;
}