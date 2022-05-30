#include "stage.hpp"

int Stage::getGameStage()
{
    return gameStage;
}

void Stage::up()
{
    gameStage += 1;
    score += 1;
}

void Stage::show()
{
    cout << "Aktualny etap > " << (gameStage + 1) << endl;
}

int Stage::end()
{
    // tutaj trzeba zaimplementować progi gwarantowane
    if(gameStage < 2)
        score = 0;
    
    gameStage = 0;

    return score;
}