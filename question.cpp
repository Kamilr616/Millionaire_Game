#include "question.hpp"

namespace
{
string trimField(const string &value)
{
    const size_t first = value.find_first_not_of(" \t\r\n");
    if (first == string::npos)
        return "";

    const size_t last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

int parseInteger(const string &value, const string &fieldName)
{
    size_t parsedCharacters = 0;
    int result;

    try
    {
        result = stoi(value, &parsedCharacters);
    }
    catch (const invalid_argument &)
    {
        throw runtime_error("Pole " + fieldName + " musi byc liczba calkowita.");
    }
    catch (const out_of_range &)
    {
        throw runtime_error("Pole " + fieldName + " jest poza zakresem typu int.");
    }

    if (parsedCharacters != value.size())
        throw runtime_error("Pole " + fieldName + " zawiera dodatkowe znaki.");

    return result;
}
}

question::question(string _text, string _answ1, string _answ2, string _answ3, string _answ4, int _correct)
{
    if (_text.empty() || _answ1.empty() || _answ2.empty() || _answ3.empty() || _answ4.empty())
        throw invalid_argument("Pytanie i wszystkie odpowiedzi musza byc niepuste.");
    if (_correct < 1 || _correct > 4)
        throw invalid_argument("Numer poprawnej odpowiedzi musi byc w zakresie 1-4.");

    text = _text;
    answ1 = _answ1;
    answ2 = _answ2;
    answ3 = _answ3;
    answ4 = _answ4;
    correct = _correct;
}

bool question::lifelineAskTheAudience(bool check5050)
{
    int votes[4] = {0, 0, 0, 0};
    const int correctIndex = getCorr() - 1;
    votes[correctIndex] = rand() % 31 + 50;

    const string answers[4] = {getAns1(), getAns2(), getAns3(), getAns4()};
    vector<int> visibleWrongAnswers;
    for (int index = 0; index < 4; ++index) {
        if (index != correctIndex && (!check5050 || answers[index] != " ")) {
            visibleWrongAnswers.push_back(index);
        }
    }

    int remainder = 100 - votes[correctIndex];
    for (size_t index = 0; index < visibleWrongAnswers.size(); ++index) {
        const bool isLast = index + 1 == visibleWrongAnswers.size();
        const int assigned = isLast ? remainder : rand() % (remainder + 1);
        votes[visibleWrongAnswers[index]] = assigned;
        remainder -= assigned;
    }
    votes[correctIndex] += remainder;

    cout << "Odpowiedzi publicznosci to: " << "A: " << votes[0] << "% " << "B: " << votes[1]
         << "% " << "C: " << votes[2] << "% " << "D: " << votes[3] << "%" << "\n";
    return true;
}

bool question::lifelinePhoneAFriend(int stepCounter, bool /*check5050*/)
{
    if (stepCounter < 5)
    {
        cout << "Uwazam, ze prawidlowa odpowiedz to "
             << static_cast<char>('A' + getCorr() - 1) << endl;
    }
    else
    {
        const string answers[4] = {getAns1(), getAns2(), getAns3(), getAns4()};
        vector<int> visibleAnswers;
        for (int index = 0; index < 4; ++index)
        {
            if (answers[index] != " ")
                visibleAnswers.push_back(index);
        }

        if (visibleAnswers.empty())
            throw logic_error("Brak widocznych odpowiedzi dla kola ratunkowego.");

        const size_t selected = static_cast<size_t>(rand()) % visibleAnswers.size();
        cout << "Nie mam pewnosci, ale mysle, ze prawidlowa odpowiedz to "
             << static_cast<char>('A' + visibleAnswers[selected]) << endl;
    }
    return true;
}

bool question::lifeline5050()
{
    string *answers[4] = {&answ1, &answ2, &answ3, &answ4};
    vector<int> wrongAnswers;
    for (int index = 0; index < 4; ++index)
    {
        if (index != getCorr() - 1)
            wrongAnswers.push_back(index);
    }

    for (int removed = 0; removed < 2; ++removed)
    {
        const size_t selected = static_cast<size_t>(rand()) % wrongAnswers.size();
        *answers[wrongAnswers[selected]] = " ";
        wrongAnswers.erase(wrongAnswers.begin() + static_cast<vector<int>::difference_type>(selected));
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
    {
        cout << "Brak" << endl;
    }

    if (showAns)
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

    while (true)
    {
        if (!(cin >> userAns))
        {
            if (cin.eof())
            {
                result = 2;
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Format odpowiedzi jest niepoprawny. Sprobuj jeszcze raz." << endl
                 << "Odpowiedz >> ";
            continue;
        }

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
                return askQuestion(lifelinesUsed, stepCount, scoreCount, showAns);
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
                return askQuestion(lifelinesUsed, stepCount, scoreCount, showAns);
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
                return askQuestion(lifelinesUsed, stepCount, scoreCount, showAns);
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


string question::getText() const
{
    return text;
}

string question::getAns1() const
{
    return answ1;
}

string question::getAns2() const
{
    return answ2;
}

string question::getAns3() const
{
    return answ3;
}

string question::getAns4() const
{
    return answ4;
}

int question::getCorr() const
{
    return correct;
}

question question::questionFromLine(string qLine)
{
    vector<string> fields;
    istringstream input(qLine);
    string field;
    while (getline(input, field, ';'))
        fields.push_back(trimField(field));

    if (fields.size() != 7)
        throw runtime_error("Niepoprawny format wiersza pytania.");

    const int questionId = parseInteger(fields[0], "ID");
    if (questionId < 1)
        throw runtime_error("ID pytania musi byc dodatnie.");

    for (size_t index = 1; index <= 5; ++index)
    {
        if (fields[index].empty())
            throw runtime_error("Pytanie i wszystkie odpowiedzi musza byc niepuste.");
    }

    const int correctAnswer = parseInteger(fields[6], "CORRECT_ANSWER");
    if (correctAnswer < 1 || correctAnswer > 4)
        throw runtime_error("Numer poprawnej odpowiedzi musi byc w zakresie 1-4.");

    return question(fields[1], fields[2], fields[3], fields[4], fields[5], correctAnswer);
}

question question::getQuestions(int stepCounter)
{
    if (stepCounter < 1 || stepCounter > 15)
        throw invalid_argument("Etap gry musi byc w zakresie 1-15.");

    const filesystem::path path = filesystem::path("questions") / (to_string(stepCounter) + ".csv");
    ifstream questions(path);
    if (!questions)
        throw runtime_error("Nie mozna otworzyc pliku " + path.string());

    const string expectedHeader = "ID;QUESTIONS;ANSWER1;ANSWER2;ANSWER3;ANSWER4;CORRECT_ANSWER";
    string line;
    if (!getline(questions, line))
        throw runtime_error("Plik " + path.string() + " jest pusty.");
    if (trimField(line) != expectedHeader)
        throw runtime_error("Plik " + path.string() + " ma niepoprawny naglowek.");

    vector<question> rows;
    int lineNumber = 1;
    while (getline(questions, line))
    {
        ++lineNumber;
        if (trimField(line).empty())
            continue;

        try
        {
            rows.push_back(questionFromLine(line));
        }
        catch (const exception &error)
        {
            throw runtime_error(path.string() + ":" + to_string(lineNumber) + ": " + error.what());
        }
    }

    if (rows.empty())
        throw runtime_error("Plik " + path.string() + " nie zawiera pytan.");

    const size_t selected = static_cast<size_t>(rand()) % rows.size();
    return rows[selected];
}
