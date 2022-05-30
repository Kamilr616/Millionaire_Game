#ifndef STAGE_HPP
#define STAGE_HPP

#include "global.hpp"

using namespace std;

class Stage
{

    private:

        int gameStage;
        int score;

    public:

        Stage();
        ~Stage();
        int getGameStage();
        int getScore();
        void up();
        int end();
        int giveup();
        
};


#endif // STAGE_HPP