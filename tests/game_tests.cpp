#include "question.hpp"
#include "stage.hpp"

#include <numeric>
#include <sstream>

namespace
{
void require(bool condition, const string &message)
{
    if (!condition)
        throw runtime_error(message);
}

template <typename Exception, typename Callable>
void requireThrows(Callable action, const string &message)
{
    try
    {
        action();
    }
    catch (const Exception &)
    {
        return;
    }
    throw runtime_error(message);
}

vector<int> numbersFrom(const string &text)
{
    vector<int> values;
    int current = -1;
    for (unsigned char character : text)
    {
        if (character >= '0' && character <= '9')
        {
            if (current < 0)
                current = 0;
            current = current * 10 + (character - '0');
        }
        else if (current >= 0)
        {
            values.push_back(current);
            current = -1;
        }
    }
    if (current >= 0)
        values.push_back(current);
    return values;
}

class OutputCapture
{
    ostringstream output;
    streambuf *original;

public:
    OutputCapture() : original(cout.rdbuf(output.rdbuf())) {}
    ~OutputCapture() { cout.rdbuf(original); }

    string take()
    {
        const string value = output.str();
        output.str("");
        output.clear();
        return value;
    }
};
}

int main()
{
    srand(1);

    question loader;
    for (int level = 1; level <= 15; ++level)
    {
        question loaded = loader.getQuestions(level);
        require(!loaded.getText().empty(), "Question bank returned an empty question.");
        require(!loaded.getAns1().empty() && !loaded.getAns2().empty()
                    && !loaded.getAns3().empty() && !loaded.getAns4().empty(),
                "Question bank returned an empty answer.");
        require(loaded.getCorr() >= 1 && loaded.getCorr() <= 4,
                "Question bank returned an invalid correct-answer index.");
    }

    requireThrows<runtime_error>([&] { loader.questionFromLine("invalid;row"); },
                                 "A row with the wrong field count was accepted.");
    requireThrows<runtime_error>([&] { loader.questionFromLine("x;Q;A;B;C;D;1"); },
                                 "A non-numeric question ID was accepted.");
    requireThrows<runtime_error>([&] { loader.questionFromLine("0;Q;A;B;C;D;1"); },
                                 "A non-positive question ID was accepted.");
    requireThrows<runtime_error>([&] { loader.questionFromLine("1;;A;B;C;D;1"); },
                                 "An empty question was accepted.");
    requireThrows<runtime_error>([&] { loader.questionFromLine("1;Q;A;B;C;D;5"); },
                                 "An out-of-range correct answer was accepted.");
    requireThrows<runtime_error>([&] { loader.questionFromLine("1;Q;A;B;C;D;1x"); },
                                 "A correct answer with a suffix was accepted.");
    requireThrows<invalid_argument>([] { question("Q", "A", "B", "C", "D", 0); },
                                    "The constructor accepted an invalid answer index.");

    OutputCapture capturedOutput;

    question audienceQuestion("Question", "A", "B", "C", "D", 1);
    for (int sample = 0; sample < 1000; ++sample)
    {
        audienceQuestion.lifelineAskTheAudience(false);
        const vector<int> votes = numbersFrom(capturedOutput.take());
        require(votes.size() == 4, "Audience output did not contain four percentages.");
        require(accumulate(votes.begin(), votes.end(), 0) == 100,
                "Audience percentages did not add up to 100.");
        require(votes[0] >= 50 && votes[0] <= 80,
                "Audience support for the correct answer was outside 50-80 percent.");
    }

    question reducedQuestion("Question", "A", "B", "C", "D", 1);
    reducedQuestion.lifeline5050();
    vector<string> reducedAnswers = {reducedQuestion.getAns1(), reducedQuestion.getAns2(),
                                     reducedQuestion.getAns3(), reducedQuestion.getAns4()};
    int hiddenAnswers = 0;
    for (size_t index = 0; index < reducedAnswers.size(); ++index)
    {
        if (reducedAnswers[index] == " ")
            ++hiddenAnswers;
    }
    require(hiddenAnswers == 2, "50:50 did not hide exactly two answers.");
    require(reducedAnswers[0] != " ", "50:50 hid the correct answer.");

    for (int sample = 0; sample < 100; ++sample)
    {
        reducedQuestion.lifelineAskTheAudience(true);
        const vector<int> votes = numbersFrom(capturedOutput.take());
        require(votes.size() == 4 && accumulate(votes.begin(), votes.end(), 0) == 100,
                "Audience percentages after 50:50 were invalid.");
        for (size_t index = 0; index < reducedAnswers.size(); ++index)
        {
            if (reducedAnswers[index] == " ")
                require(votes[index] == 0, "The audience voted for a hidden answer.");
        }

        reducedQuestion.lifelinePhoneAFriend(10, true);
        const string suggestion = capturedOutput.take();
        require(!suggestion.empty(), "Phone-a-friend returned no suggestion.");
        const char label = suggestion[suggestion.size() - 2];
        require(label >= 'A' && label <= 'D', "Phone-a-friend returned an invalid label.");
        require(reducedAnswers[static_cast<size_t>(label - 'A')] != " ",
                "Phone-a-friend suggested a hidden answer.");
    }

    const vector<int> prizes = {100, 200, 300, 500, 1000, 2000, 4000, 8000,
                                16000, 32000, 64000, 125000, 250000, 500000, 1000000};
    Stage ladder;
    for (size_t level = 0; level < prizes.size(); ++level)
    {
        ladder.up();
        capturedOutput.take();
        require(ladder.getGameStage() == static_cast<int>(level + 1),
                "Stage counter did not advance.");
        require(ladder.getScore() == prizes[level], "Prize ladder contains an invalid value.");
    }
    require(ladder.giveup() == 1000000, "Give-up payout at the final level was invalid.");
    require(ladder.getGameStage() == 0 && ladder.getScore() == 0,
            "Give-up did not reset the stage.");

    for (int completed = 0; completed <= 15; ++completed)
    {
        Stage game;
        for (int level = 0; level < completed; ++level)
        {
            game.up();
            capturedOutput.take();
        }

        const int expected = completed >= 15 ? 1000000
                           : completed >= 10 ? 32000
                           : completed >= 5  ? 1000
                                             : 0;
        require(game.end() == expected, "Guaranteed payout is invalid at a boundary.");
        require(game.getGameStage() == 0 && game.getScore() == 0,
                "Game end did not reset the stage.");
    }

    return 0;
}
