# 💰 Millionaire Game

[![C++](https://img.shields.io/badge/C++-console%20game-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> 🇵🇱 [Wersja polska](README.pl.md)

> 🗓️ **Project period:** 2022

A console implementation of the classic **"Who Wants to Be a Millionaire?"** quiz game, written in C++. Answer 12 increasingly difficult questions, use your lifelines wisely, and win the (virtual) million!

## ✨ Features

- ❓ **12 difficulty levels** — question pools loaded from CSV files (`questions/1.csv` … `15.csv`), easy to extend with your own questions
- 🛟 **Three lifelines** — *50:50* (removes two wrong answers), *phone a friend*, and *ask the audience*
- 📊 **Score tracking** — correct-answer counter and give-up option (walk away with your winnings)
- ⚙️ **Settings menu** — e.g. toggle revealing the correct answer
- 🖥️ Lightweight, dependency-free console UI

## 🎮 How to play

After launching the game you'll see the main menu:

| Key | Action |
|-----|--------|
| `1` | New game |
| `9` | Settings |
| `0` | Exit |

During the game the available lifelines are shown at the top, followed by the question and four answers. Pick the right answer to advance; a wrong answer (or giving up) ends the game. Answer all questions to win the million!

```text
Gra milionerzy
1. Nowa gra
9. Ustawienia
0. Wyjscie
> 1

Kola ratunkowe:  [50:50]  [Telefon]  [Publicznosc]
Pytanie 1  (500 zl)
Kandydat na wysokie stanowisko czesto nie musi miec kwalifikacji, o ile ma mocne:
  1. lydki      2. kolana
  3. plecy      4. rece
Twoja odpowiedz: 3
Poprawna odpowiedz! Grasz dalej...
```

## 📋 Question format

Questions live in `questions/<level>.csv` — one file per difficulty level — as semicolon-separated rows:

```csv
ID;QUESTIONS;ANSWER1;ANSWER2;ANSWER3;ANSWER4;CORRECT_ANSWER
1;Which muscle should a candidate have strong?;calves;knees;back;arms;3
```

`CORRECT_ANSWER` is the index (1–4) of the correct answer. Add your own questions by appending rows.

## 📂 Repository structure

| Path | Description |
|------|-------------|
| `main.cpp` | Entry point and game loop |
| `stage.{hpp,cpp}` | Game stage logic (menu, rounds, lifelines) |
| `question.{hpp,cpp}` | Question model and CSV loading |
| `global.hpp` | Shared definitions |
| `questions/*.csv` | Question banks per difficulty level |

## 🚀 Building

```bash
git clone https://github.com/Kamilr616/Millionaire_Game.git
cd Millionaire_Game
g++ -std=c++17 main.cpp stage.cpp question.cpp -o millionaire
./millionaire
```

> The `questions/` directory must be next to the executable at runtime.

A prebuilt Windows executable can also be published under the repository's **Releases**.

## 👥 Team

| Member | Contribution |
|--------|--------------|
| **Kamil Rataj** | Repository setup, programming |
| **Kacper Krzyżkowski** | Programming |
| **Tomasz Porwisz** | Question authoring & proofreading, documentation |

## 📄 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**Kamil Rataj** — [GitHub](https://github.com/Kamilr616) · [LinkedIn](https://www.linkedin.com/in/kamil-r-153ab7121/)
