#ifndef STAGE_HPP
#define STAGE_HPP

#include "global.hpp"

using namespace std;

class Stage
{

    private:

        int gameStage = 0;


    public:

        Stage() = default;
        int getGameStage();
        
};


#endif // STAGE_HPP