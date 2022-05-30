#ifndef STAGE_HPP
#define STAGE_HPP

#include "global.hpp"

using namespace std;

class Stage
{

    private:

        int gameStage = 0;
        int score = 0;


    public:

        Stage() = default;
        int getGameStage();
        void up();
        void show();
        int end();
        
        
};


#endif // STAGE_HPP