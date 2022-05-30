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

void Stage::up()
{
    switch(gameStage)   //próg gwarantowany
    {
        case 5:
            cout << "Prog gwarantowany 1000 zl" << endl;
            system("PAUSE");
            score = 1000;
            break;
        case 10:
            cout << "Prog gwarantowany 32 000 zl" << endl;
            system("PAUSE");
            score = 32000;
            break;
        case 16:
            score = 1000000;
            break;
        default:
            break;
    }
    gameStage += 1;      //nastepny etap
}

void Stage::show()
{
    cout << "Aktualny etap > " << (gameStage + 1) << endl;
}

int Stage::end()
{
    int result = score;

    if(gameStage > 15)
    {
        cout << "Wyglales milion zlotych !!!" << endl;
    }
    // tutaj trzeba zaimplementować przypadek zrezygnowania
    
    
    gameStage = 0;
    score = 0;

    return result;
}