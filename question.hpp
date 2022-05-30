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

        question questionFromLine(string qLine);
        question getQuestions(int stepCounter);

};


#endif // QUESTION_HPP