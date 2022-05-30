#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "global.hpp"

using namespace std;

class question 
{

    private:

        string text,answ1,answ2,answ3,answ4;
        int correct;

    public:

        question() = default;
        question(string _text, string _answ1, string _answ2, string _answ3, string _answ4, int _correct);

        string getText();
        string getAns1();
        string getAns2();
        string getAns3();
        string getAns4();
        int getCorr();
        int askQuestion(bool lifelinesUsed[3],int stepCount, int scoreCount, bool showAns);

        question questionFromLine(string qLine);
        question getQuestions(int stepCounter);
        bool lifeline5050();
        bool lifelinePhoneAFriend(int stepCounter);
        bool lifelineAskTheAudience();

};


#endif // QUESTION_HPP