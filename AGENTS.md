# AGENTS.md

Guidance for AI coding agents working in this repository.

## Project
Console **"Who Wants to Be a Millionaire"** game in **C++**. Questions are loaded from
per-level CSV files; three lifelines are implemented (50:50, phone-a-friend,
ask-the-audience). 15 question levels.

## Layout
- `main.cpp` — entry point / game loop · `stage.{hpp,cpp}` — prize ladder.
- `question.{hpp,cpp}` — question loading + lifelines.
- `global.hpp` — shared helpers · `questions/1.csv … 15.csv` — question data.
- `tests/game_tests.cpp` — tests · `docs/gameplay.png` — screenshot.

## Build / run / test
- Build: `g++ -std=c++17 main.cpp stage.cpp question.cpp -o millionaire`
  (C++17 is required for `<filesystem>`).
- Test: `g++ -std=c++17 -I. tests/game_tests.cpp stage.cpp question.cpp -o millionaire-tests`
  and run `./millionaire-tests` from the repository root.
- Run the game with the `questions/` folder next to the executable (the binary
  changes its working directory to its own directory).
- GitHub Actions builds the game and runs tests with sanitizers on Ubuntu.

## Conventions & good practices
- Do **not** `#include "*.cpp"` — compile translation units separately (avoids ODR/link
  errors). Header-only helpers used across TUs should be `inline`.
- Answers are labelled **A–D**; keep prose, the CSV format, and any mockups consistent.
- CSV rows have 7 fields with the correct-answer index in `1..4`; validate on load.
- Commit **no compiled binaries**; update **both** `README.md` and `README.pl.md`.

## Documentation
- [README.md](README.md) · [README.pl.md](README.pl.md)
- [Technical documentation](docs/TECHNICAL_DOCUMENTATION.md) · [Polski](docs/TECHNICAL_DOCUMENTATION.pl.md)
- License: **MIT** — see [LICENSE](LICENSE).

_Educational / portfolio project._
