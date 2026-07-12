# 💰 Gra Milionerzy

[![C++](https://img.shields.io/badge/C++-gra%20konsolowa-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Licencja: MIT](https://img.shields.io/badge/Licencja-MIT-yellow.svg)](LICENSE)

> 🇬🇧 [English version](README.md)

> 🗓️ **Okres realizacji:** 2022

Konsolowa implementacja klasycznego teleturnieju **„Milionerzy"**, napisana w C++. Odpowiedz na 12 coraz trudniejszych pytań, mądrze korzystaj z kół ratunkowych i wygraj (wirtualny) milion!

## ✨ Funkcje

- ❓ **12 poziomów trudności** — pule pytań wczytywane z plików CSV (`questions/1.csv` … `15.csv`), łatwe do rozszerzenia o własne pytania
- 🛟 **Trzy koła ratunkowe** — *50:50* (usuwa dwie błędne odpowiedzi), *telefon do przyjaciela* i *pytanie do publiczności*
- 📊 **Śledzenie wyniku** — licznik poprawnych odpowiedzi i możliwość poddania się (odejście z wygraną)
- ⚙️ **Menu ustawień** — m.in. opcja pokazywania poprawnych odpowiedzi
- 🖥️ Lekki interfejs konsolowy bez zewnętrznych zależności

## 🎮 Jak grać

Po uruchomieniu gry zobaczysz menu główne:

| Klawisz | Akcja |
|---------|-------|
| `1` | Nowa gra |
| `9` | Ustawienia |
| `0` | Wyjście |

Podczas gry u góry wyświetlane są dostępne koła ratunkowe, poniżej pytanie i cztery odpowiedzi. Poprawna odpowiedź przenosi do kolejnego pytania; błędna odpowiedź (lub poddanie się) kończy grę. Odpowiedz na wszystkie pytania, aby wygrać milion!

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

## 📋 Format pytań

Pytania znajdują się w `questions/<poziom>.csv` — jeden plik na poziom trudności — jako wiersze rozdzielone średnikami:

```csv
ID;QUESTIONS;ANSWER1;ANSWER2;ANSWER3;ANSWER4;CORRECT_ANSWER
1;Jaki miesien powinien miec mocny kandydat?;lydki;kolana;plecy;rece;3
```

`CORRECT_ANSWER` to numer (1–4) poprawnej odpowiedzi. Własne pytania dodasz, dopisując kolejne wiersze.

## 📂 Struktura repozytorium

| Ścieżka | Opis |
|---------|------|
| `main.cpp` | Punkt wejścia i pętla gry |
| `stage.{hpp,cpp}` | Logika etapów gry (menu, rundy, koła ratunkowe) |
| `question.{hpp,cpp}` | Model pytania i wczytywanie CSV |
| `global.hpp` | Wspólne definicje |
| `questions/*.csv` | Banki pytań według poziomu trudności |

## 🚀 Budowanie

```bash
git clone https://github.com/Kamilr616/Millionaire_Game.git
cd Millionaire_Game
g++ -std=c++17 main.cpp stage.cpp question.cpp -o milionerzy
./milionerzy
```

> Katalog `questions/` musi znajdować się obok pliku wykonywalnego.

Gotowy plik wykonywalny dla Windows można też opublikować w sekcji **Releases** repozytorium.

## 👥 Zespół

| Członek zespołu | Wkład |
|-----------------|-------|
| **Kamil Rataj** | Utworzenie repozytorium, programowanie |
| **Kacper Krzyżkowski** | Programowanie |
| **Tomasz Porwisz** | Tworzenie i poprawa pytań, dokumentacja |

## 📄 Licencja

Projekt udostępniony na licencji [MIT](LICENSE).

## 👤 Autor

**Kamil Rataj** — [GitHub](https://github.com/Kamilr616) · [LinkedIn](https://www.linkedin.com/in/kamil-r-153ab7121/)
