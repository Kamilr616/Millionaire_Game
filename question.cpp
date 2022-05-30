#include "question.hpp"


question::question(string _text, string _answ1, string _answ2, string _answ3, string _answ4, int _correct)
{
    text = _text;
    answ1 = _answ1;
    answ2 = _answ2;
    answ3 = _answ3;
    answ4 = _answ4;
    correct = _correct;
}

bool question::askQuestion() //Wyświelta pytanie i odpowiedzi, zwraca true jeśli odp jesy poprawna
{
    bool result;
    char userAns;
    
    result = 0;

    cout << "Pytanie > " << getText() << endl
         << "Odpowiedzi: " << endl
         << "A > " << getAns1() << endl
         << "B > " << getAns2() << endl
         << "C > " << getAns3() << endl
         << "D > " << getAns4() << endl
         << "Poprawna odpowiedz "<< getCorr() << endl
         << "Odpowiedz >> ";
    cin >> userAns;

    if (((int)userAns - 64) == getCorr())
    {
        cout << "Dobrze!" << endl;
        result = true;       
    }

    else
    {
        cout << "Zle!" << endl;
        result = false;
    }

    cout << "Poprawna odpowiedz to ";

    switch (getCorr())
    {
    case 1:
        cout << getAns1();
        break;
    case 2:
        cout << getAns2();
        break;
    case 3:
        cout << getAns3();
        break;
    case 4:
        cout << getAns4();
        break;
    }
    cout << endl;

    return result;
}


string question::getText()
{
    return text;
}

string question::getAns1()
{
    return answ1;
}

string question::getAns2()
{
    return answ2;
}

string question::getAns3()
{
    return answ3;
}

string question::getAns4()
{
    return answ4;
}

int question::getCorr()
{
    return correct;
}

question question::questionFromLine(string qLine) // funkcja dzieli linijkę z pytaniem i wrzuca w obiekt pytania
{
    string q1, a1, a2, a3, a4, corr, id;
    istringstream temp;

    temp.str(qLine);
    getline(temp, id, ';');
    getline(temp, q1, ';');
    getline(temp, a1, ';');
    getline(temp, a2, ';');
    getline(temp, a3, ';');
    getline(temp, a4, ';');
    getline(temp, corr, '\n');
   // stoi(corr)
    question currQuestion(q1, a1, a2, a3, a4, 1);

    return currQuestion; //zwraca obiekt z gotowym pytaniem
}

question question::getQuestions(int stepCounter) // numer etapu jako argument
{ 
    ifstream questions;

    if(stepCounter == 1){
        questions.open("questions/1.csv");
    }
    else if(stepCounter == 2){
        questions.open("questions/2.csv");
    }
    else if(stepCounter == 3){
        questions.open("questions/3.csv");
    }
    else if(stepCounter == 4){
        questions.open("questions/4.csv");
    }
    else if(stepCounter == 5){
        questions.open("questions/5.csv");
    }
    else if(stepCounter == 6){
        questions.open("questions/6.csv");
    }
    else if(stepCounter == 7){
        questions.open("questions/7.csv");
    }
    else if(stepCounter == 8){
        questions.open("questions/8.csv");
    }
    else if(stepCounter == 9){
        questions.open("questions/9.csv");
    }
    else if(stepCounter == 10){
        questions.open("questions/10.csv");
    }
    else if(stepCounter == 11){
        questions.open("questions/11.csv");
    }
    else if(stepCounter == 12){
        questions.open("questions/12.csv");
    }
    else if(stepCounter == 13){
        questions.open("questions/13.csv");
    }
    else if(stepCounter == 14){
        questions.open("questions/14.csv");
    }
    else if(stepCounter == 15){
        questions.open("questions/15.csv");
    }
    string stepQuestions[12]; //tablica trzyma każdą linijke z pliku z pytaniami, na logike rozmiar powinien byc 11 ale wtedy nie dziala xd
    int qCounter = 0;

    while(questions.good())
    {
        string line;
        getline(questions, line, '\n');
        stepQuestions[qCounter] = line;        
        qCounter++;   
    }
    questions.close();
    question theQuestion;
    theQuestion = questionFromLine(stepQuestions[rand() % 10 + 1]); //losowanie pytania ktore znajdzie sie w zestawie 15 pytan
   
    return theQuestion;
}
