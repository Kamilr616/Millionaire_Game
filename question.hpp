#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "global.hpp"

using namespace std;

class question 
{

    private:

        string text,answ1,answ2,answ3,answ4;
        int correct = 0;

    public:

        question() = default;
        question(string _text, string _answ1, string _answ2, string _answ3, string _answ4, int _correct);

        string getText() const;
        string getAns1() const;
        string getAns2() const;
        string getAns3() const;
        string getAns4() const;

        int getCorr() const;
        int askQuestion(bool lifelinesUsed[3], int stepCount, int scoreCount, bool showAns);
        void showAnswear();

        question questionFromLine(string qLine);
        question getQuestions(int stepCounter);

        bool lifeline5050();
        bool lifelinePhoneAFriend(int stepCounter, bool check5050);
        bool lifelineAskTheAudience(bool check5050);

};

#endif // QUESTION_HPP