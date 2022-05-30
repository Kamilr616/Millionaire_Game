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
            cout << "Próg gwarantowany 1000 zl" << endl;
            score = 1000;
            break;
        case 10:
            cout << "Próg gwarantowany 32 000 zl" << endl;
            score = 32000;
            break;
        case 16:
            cout << "Glowna nagroda 1 mln zl!" << endl;
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

    gameStage = 0;

    // tutaj trzeba zaimplementować przypadek zrezygnowania

    return score;
}