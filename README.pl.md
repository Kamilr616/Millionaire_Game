# 💰 Gra Milionerzy

[![C++](https://img.shields.io/badge/C++-gra%20konsolowa-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![C++ CI](https://github.com/Kamilr616/Millionaire_Game/actions/workflows/ci.yml/badge.svg)](https://github.com/Kamilr616/Millionaire_Game/actions/workflows/ci.yml)
[![GitHub release](https://img.shields.io/github/v/release/Kamilr616/Millionaire_Game)](https://github.com/Kamilr616/Millionaire_Game/releases/latest)
[![Licencja: MIT](https://img.shields.io/badge/Licencja-MIT-yellow.svg)](LICENSE)

> 🇬🇧 [English version](README.md)

> 🗓️ **Okres realizacji:** 2022

> 📘 [Dokumentacja techniczna](docs/TECHNICAL_DOCUMENTATION.pl.md)

Konsolowa implementacja klasycznego teleturnieju **„Milionerzy”**, napisana w C++. Odpowiedz na po jednym pytaniu z 15 poziomów, mądrze korzystaj z kół ratunkowych i wygraj (wirtualny) milion!

<p align="center">
  <img src="docs/gameplay.png" alt="Rozgrywka konsolowa w grze Milionerzy" width="760"/>
</p>

## ✨ Funkcje

- ❓ **15 poziomów pytań** — walidowane pule pytań wczytywane z plików CSV (`questions/1.csv` … `15.csv`), łatwe do rozszerzenia o własne pytania
- 🛟 **Trzy koła ratunkowe** — *50:50* (usuwa dwie błędne odpowiedzi), *telefon do przyjaciela* i *pytanie do publiczności*
- 📊 **Śledzenie wygranej** — bieżący poziom, nagroda i możliwość poddania się (odejście z wygraną)
- ⚙️ **Menu ustawień** — m.in. opcja pokazywania poprawnych odpowiedzi
- 🖥️ Lekki interfejs konsolowy bez zewnętrznych zależności

## 🎮 Jak grać

Po uruchomieniu gry zobaczysz menu główne:

| Klawisz | Akcja |
|---------|-------|
| `1` | Nowa gra |
| `2` | Ustawienia |
| `0` | Wyjście |

Podczas gry u góry wyświetlane są dostępne koła ratunkowe, poniżej pytanie i cztery odpowiedzi oznaczone literami `A`–`D`. Wpisanie poprawnej litery przenosi do kolejnego pytania; błędna odpowiedź (lub poddanie się) kończy grę. Odpowiedz na wszystkie pytania, aby wygrać milion!

| Klawisz w grze | Akcja |
|----------------|-------|
| `A`–`D` (lub `a`–`d`) | Wybór odpowiedzi |
| `%` | Koło 50:50 |
| `f` | Telefon do przyjaciela |
| `p` | Pytanie do publiczności |
| `E` lub `e` | Rezygnacja z gry |

```text
Gra milionerzy
1. Nowa gra
2. Ustawienia programu
0. Zakoncz

Aktualny etap > 1
Wynik > 0 zL
Dostepne kola ratunkowe:
-50/50 (wprowadz '%' na klawiaturze)
-Telefon do przyjaciela (wprowadz 'f' na klawiaturze)
-Pytanie do publicznosci (wprowadz 'p' na klawiaturze)

Pytanie > Kandydat na wysokie stanowisko czesto nie musi miec odpowiednich kwalifikacji, o ile ma mocne:
Odpowiedzi:
A > lydki
B > kolana
C > plecy
D > rece

E > Poddaj sie - Koniec gry
Odpowiedz >> C
Dobrze!

   Poprawna odpowiedz to > plecy
Wygrales 100 zl
```

## 📋 Format pytań

Pytania znajdują się w `questions/<poziom>.csv` — jeden plik na poziom trudności — jako wiersze rozdzielone średnikami:

```csv
ID;QUESTIONS;ANSWER1;ANSWER2;ANSWER3;ANSWER4;CORRECT_ANSWER
1;Jaki miesien powinien miec mocny kandydat?;lydki;kolana;plecy;rece;3
```

`CORRECT_ANSWER` to numer (1–4) poprawnej odpowiedzi. Loader sprawdza dokładny nagłówek i każdy niepusty wiersz przed wylosowaniem pytania. Własne pytania dodasz, dopisując kolejne wiersze.

## 📂 Struktura repozytorium

| Ścieżka | Opis |
|---------|------|
| `main.cpp` | Punkt wejścia i pętla gry |
| `stage.{hpp,cpp}` | Etap gry, drabinka nagród i progi gwarantowane |
| `question.{hpp,cpp}` | Model pytania i wczytywanie CSV |
| `global.hpp` | Wspólne definicje |
| `questions/*.csv` | Banki pytań według poziomu trudności |

## 🚀 Budowanie

```bash
git clone https://github.com/Kamilr616/Millionaire_Game.git
cd Millionaire_Game
g++ -std=c++17 main.cpp stage.cpp question.cpp -o millionaire
./millionaire
```

> Katalog `questions/` musi znajdować się obok pliku wykonywalnego.

### Testy

```bash
g++ -std=c++17 tests/game_tests.cpp stage.cpp question.cpp -I. -o millionaire-tests
./millionaire-tests
```

GitHub Actions uruchamia ten sam build i testy regresji przy każdym pushu i pull requeście.

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
