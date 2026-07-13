#include "question.hpp"
#include "stage.hpp"

#include <sstream>

int main()
{
    srand(1);

    question loader;
    for (int level = 1; level <= 15; ++level) {
        for (int sample = 0; sample < 20; ++sample) {
            question loaded = loader.getQuestions(level);
            if (loaded.getText().empty() || loaded.getCorr() < 1 || loaded.getCorr() > 4) {
                throw runtime_error("Question bank returned invalid data.");
            }
        }
    }

    bool invalidRowRejected = false;
    try {
        loader.questionFromLine("invalid;row");
    } catch (const runtime_error &) {
        invalidRowRejected = true;
    }
    if (!invalidRowRejected) {
        throw runtime_error("Invalid CSV row was accepted.");
    }

    question audienceQuestion("Question", "A", "B", "C", "D", 1);
    ostringstream output;
    streambuf *originalOutput = cout.rdbuf(output.rdbuf());
    for (int sample = 0; sample < 1000; ++sample) {
        audienceQuestion.lifelineAskTheAudience(false);
    }
    cout.rdbuf(originalOutput);

    Stage game;
    for (int level = 0; level < 10; ++level) {
        game.up();
    }
    if (game.giveup() != 32000 || game.getGameStage() != 0) {
        throw runtime_error("Give-up payout or stage reset is invalid.");
    }

    for (int level = 0; level < 7; ++level) {
        game.up();
    }
    if (game.end() != 1000 || game.getGameStage() != 0) {
        throw runtime_error("Guaranteed payout or stage reset is invalid.");
    }

    return 0;
}
