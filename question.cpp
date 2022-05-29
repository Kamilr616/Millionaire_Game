#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "global.h"
using namespace std;

class question {
    private:
    string text,answ1,answ2,answ3,answ4;
    int correct;
    public:
    question() = default;
    question(string _text, string _answ1, string _answ2, string _answ3, string _answ4, int _correct) { 
        text = _text;
        answ1 = _answ1;
        answ2 = _answ2;
        answ3 = _answ3;
        answ4 = _answ4;
        correct = _correct;
    }
    string getText(){
        return text;
    }
    string getAns1(){
        return answ1;
    }
    string getAns2(){
        return answ2;
    }
    string getAns3(){
        return answ3;
    }
    string getAns4(){
        return answ4;
    }
    int getCorr(){
        return correct;
    }
};