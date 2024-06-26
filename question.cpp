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

bool question::lifelineAskTheAudience(bool check5050)
{
    int g1 = 0, g2 = 0, g3 = 0, g4 = 0;
    int total = 100;
    if(check5050 == false){
        if(getCorr() == 1){
            g1 = (int)(rand() % 50 + 50);
            int remainder = total - g1;
            total = remainder;
            g2 = (int)(rand() % remainder + 1);
            remainder = total - g2;
            total = remainder;
            g3 = (int)(rand() % remainder + 1);
            g4 = total - g3;
        }
        if(getCorr() == 2){
            g2 = (int)(rand() % 50 + 50);
            int remainder = total - g2;
            total = remainder;
            g1 = (int)(rand() % remainder + 1);
            remainder = total - g1;
            total = remainder;
            g3 = (int)(rand() % remainder + 1);
            g4 = total - g3;
        }
        if(getCorr() == 3){
            g3 = (int)(rand() % 50 + 50);
            int remainder = total - g3;
            total = remainder;
            g2 = (int)(rand() % remainder + 1);
            remainder = total - g2;
            total = remainder;
            g1 = (int)(rand() % remainder + 1);
            g4 = total - g1;
        }
        if(getCorr() == 4){
            g4 = (int)(rand() % 50 + 50);
            int remainder = total - g4;
            total = remainder;
            g2 = (int)(rand() % remainder + 1);
            remainder = total - g2;
            total = remainder;
            g3 = (int)(rand() % remainder + 1);
            g1 = total - g3;
        }
    }
    else{
            if(getCorr() == 1){
            g1 = (int)(rand() % 50 + 50);
            if(getAns2() != " ") g2 = 100 - g1;
            if(getAns3() != " ") g3 = 100 - g1;
            if(getAns4() != " ") g4 = 100 - g1;
            
        }
        if(getCorr() == 2){
            g2 = (int)(rand() % 50 + 50);
            if(getAns1() != " ") g1 = 100 - g2;
            if(getAns3() != " ") g3 = 100 - g2;
            if(getAns4() != " ") g4 = 100 - g2;
        }
        if(getCorr() == 3){
            g3 = (int)(rand() % 50 + 50);
            if(getAns2() != " ") g2 = 100 - g3;
            if(getAns1() != " ") g1 = 100 - g3;
            if(getAns4() != " ") g4 = 100 - g3;
        }
        if(getCorr() == 4){
            g4 = (int)(rand() % 50 + 50);
            if(getAns2() != " ") g2 = 100 - g4;
            if(getAns3() != " ") g3 = 100 - g4;
            if(getAns1() != " ") g1 = 100 - g4;
        }
    }
    cout << "Odpowiedzi publicznosci to: " << "A: " << g1 << "% " << "B: " << g2 << "% " << "C: " << g3 << "% " << "D: " << g4 << "%" << "\n"; 
    return true;
}

bool question::lifelinePhoneAFriend(int stepCounter, bool check5050)
{
    int guess;
    if(stepCounter < 5){
        cout << "Uwazam, ze prawidlowa odpowiedz to ";
        switch (getCorr())
        {
        case 1:
            cout << "A" << endl;
            break;
        case 2:
            cout << "B" << endl;
            break;
        case 3:
            cout << "C" << endl;
            break;
        case 4:
            cout << "D" << endl;
            break;
        }
    }
    else
    {   
        int guessed = 0;
        cout << "Nie mam pewnosci, ale mysle, ze prawidlowa odpowiedz to ";
        while (guessed < 1){
        guess = (int)(rand() % 4 + 1);
        switch (guess)
            {
            case 1:
                if(getAns1() != " "){
                    cout << "A" << endl;
                    guessed = 1;
                    break;
                }
            case 2:
                if(getAns2() != " "){
                    cout << "B" << endl;
                    guessed = 1;
                    break;
                }
            case 3:
                if(getAns3() != " "){
                    cout << "C" << endl;
                    guessed = 1;
                    break;
                }
            case 4:
                if(getAns4() != " "){
                    cout << "D" << endl;
                    guessed = 1;
                    break;
                }
            }
        }
    }
    return true;
}

bool question::lifeline5050()
{
    int ffCounter = 0;
    int randQ[2];
    while(ffCounter < 2){
        randQ[ffCounter] = ((int)(rand() % 4 + 1));
        if(ffCounter == 0){
            if(randQ[ffCounter] != getCorr())
            {
                ffCounter++;
            }
        }
        else if(ffCounter == 1){
            if(randQ[ffCounter] != getCorr() && randQ[ffCounter] != randQ[ffCounter-1])
            {
                ffCounter++;
            }
        }
    }

    for(int i = 0; i<2; i++)
    {
        if(randQ[i] == 1)
        {
            answ1 = " ";
        }
        else if(randQ[i] == 2)
        {
            answ2 = " ";
        }
        else if(randQ[i] == 3)
        {
            answ3 = " ";
        }
        else if(randQ[i] == 4)
        {
            answ4 = " ";
        }
    }
    return true;
}

void question::showAnswear()
{
    cout << endl << "   Poprawna odpowiedz to > ";
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
}

int question::askQuestion(bool lifelinesUsed[3], int stepCount, int scoreCount, bool showAns) //Wyświelta pytanie i odpowiedzi, zwraca true jeśli odp jesy poprawna
{
    int result;
    char userAns;
    
    result = 0;
    userAns = 'h';

    cout << "Aktualny etap > " << (stepCount+1) << endl
         << "Wynik > " << scoreCount  << " zL" << endl
         << "Dostepne kola ratunkowe:" << endl;
    if (lifelinesUsed[0] == false)
        cout << "-50/50 (wprowadz '%' na klawiaturze)" << endl;
    if (lifelinesUsed[1] == false)
        cout << "-Telefon do przyjaciela (wprowadz 'f' na klawiaturze)" << endl;
    if (lifelinesUsed[2] == false)
        cout << "-Pytanie do publicznosci (wprowadz 'p' na klawiaturze)" << endl;
    if (lifelinesUsed[0] == true && lifelinesUsed[1] == true && lifelinesUsed[2] == true)
        cout << "Brak" << endl;

        if(showAns)
            showAnswear();

        cout << endl
             << "Pytanie > " << getText() << endl
             << "Odpowiedzi: " << endl
             << "A > " << getAns1() << endl
             << "B > " << getAns2() << endl
             << "C > " << getAns3() << endl
             << "D > " << getAns4() << endl
             << endl
             << "E > Poddaj sie - Koniec gry" << endl
             << "Odpowiedz >> ";

        while ((userAns != 'A') || (userAns != 'B') || (userAns != 'E') || (userAns != 'e') || (userAns != 'C') || (userAns != 'D') || (userAns != 'a') || (userAns != 'b') || (userAns != 'c') || (userAns != 'd') || (userAns != '%') || (userAns != 'f') || (userAns != 'p'))
        {
            cin >> userAns;

            if ((userAns == 'E') || (userAns == 'e'))
            {
                result = 2;
                break;
            }

            if (userAns == 'A' || userAns == 'B' || userAns == 'C' || userAns == 'D')
            {
                if (((int)userAns - 64) == getCorr())
                {
                    cout << "Dobrze!" << endl;
                    result = 1;
                    break;
                }
                else
                {
                    cout << "Zle!" << endl;
                    result = 0;
                    break;
                }
            }

            if (userAns == 'a' || userAns == 'b' || userAns == 'c' || userAns == 'd')
            {
                if (((int)userAns - 96) == getCorr())
                {
                    cout << "Dobrze!" << endl;
                    result = 1;
                    break;
                }
                else
                {
                    cout << "Zle!" << endl;
                    result = 0;
                    break;
                }
            }
            else if ((userAns) == '%')
            { // wprowadzenie 50/50
                if (lifelinesUsed[0] == false)
                {
                    clear_screen();
                    lifelinesUsed[0] = lifeline5050();
                    if (askQuestion(lifelinesUsed, stepCount, scoreCount, showAns) == 1)
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                {
                    cout << "Uzyles juz tego kola ratunkowego (50/50)" << endl
                         << "Odpowiedz >> ";
                }
            }
            else if ((userAns) == 'f')
            { // wprowadzenie phone a friend
                if (lifelinesUsed[1] == false)
                {
                    clear_screen();
                    lifelinesUsed[1] = lifelinePhoneAFriend(stepCount, lifelinesUsed[0]);
                    if (askQuestion(lifelinesUsed, stepCount, scoreCount, showAns) == 1)
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                {
                    cout << "Uzyles juz tego kola ratunkowego (Telefon do przyjaciela)" << endl
                         << "Odpowiedz >> ";
                }
            }
            else if ((userAns) == 'p')
            { // wprowadzenie audience poll
                if (lifelinesUsed[2] == false)
                {
                    clear_screen();
                    lifelinesUsed[2] = lifelineAskTheAudience(lifelinesUsed[0]);
                    if (askQuestion(lifelinesUsed, stepCount, scoreCount, showAns) == 1)
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                {
                    cout << "Uzyles juz tego kola ratunkowego (Pytanie do publicznosci)" << endl
                         << "Odpowiedz >> ";
                }
            }
            else
            {
                cout << "Format odpowiedzi jest niepoprawny. Sprobuj jeszcze raz." << endl
                     << "Odpowiedz >> ";
            }
        }

    showAnswear();

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
    
    question currQuestion(q1, a1, a2, a3, a4, stoi(corr));

    return currQuestion; //zwraca obiekt z gotowym pytaniem
}

question question::getQuestions(int stepCounter) // numer etapu jako argument
{ 
    ifstream questions;

    if(stepCounter == 1)
    {
        questions.open("questions/1.csv");
    }
    else if(stepCounter == 2)
    {
        questions.open("questions/2.csv");
    }
    else if(stepCounter == 3)
    {
        questions.open("questions/3.csv");
    }
    else if(stepCounter == 4)
    {
        questions.open("questions/4.csv");
    }
    else if(stepCounter == 5)
    {
        questions.open("questions/5.csv");
    }
    else if(stepCounter == 6)
    {
        questions.open("questions/6.csv");
    }
    else if(stepCounter == 7)
    {
        questions.open("questions/7.csv");
    }
    else if(stepCounter == 8)
    {
        questions.open("questions/8.csv");
    }
    else if(stepCounter == 9)
    {
        questions.open("questions/9.csv");
    }
    else if(stepCounter == 10)
    {
        questions.open("questions/10.csv");
    }
    else if(stepCounter == 11)
    {
        questions.open("questions/11.csv");
    }
    else if(stepCounter == 12)
    {
        questions.open("questions/12.csv");
    }
    else if(stepCounter == 13)
    {
        questions.open("questions/13.csv");
    }
    else if(stepCounter == 14)
    {
        questions.open("questions/14.csv");
    }
    else if(stepCounter == 15)
    {
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
