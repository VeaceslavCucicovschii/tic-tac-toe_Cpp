# Tic Tac Toe (C++)

Joc Tic Tac Toe în consolă, scris în C++.

## Structura proiectului

| Fișier | Rol |
|---|---|
| `GameEngine.hpp` / `GameEngine.cpp` | Logica jocului: tabla, jucătorul curent, regulile |
| `Renderer.hpp` / `Renderer.cpp` | Afișarea jocului pe ecran |
| `Listener.hpp` / `Listener.cpp` | Citirea mutărilor de la jucător |
| `main.cpp` | Punctul de intrare în program |
| `build.cmd` | Script pentru construirea proiectului |

## Construirea proiectului

### Folosind scriptul de build

Din folderul proiectului, rulați:

```
.\build.cmd
```

Scriptul compilează fiecare fișier `.cpp` într-un fișier obiect (`.o`), apoi le leagă în executabilul `tictactoe.exe`. Dacă o compilare eșuează, scriptul se oprește.

### Compilare manuală

1. Compilarea fiecărui fișier sursă într-un fișier obiect:

```
g++ -Wall -std=c++17 -c GameEngine.cpp -o GameEngine.o
g++ -Wall -std=c++17 -c Renderer.cpp -o Renderer.o
g++ -Wall -std=c++17 -c Listener.cpp -o Listener.o
g++ -Wall -std=c++17 -c main.cpp -o main.o
```

2. Legarea fișierelor obiect într-un executabil:

```
g++ GameEngine.o Renderer.o Listener.o main.o -o tictactoe.exe
```

## Rulare

```
.\tictactoe.exe
```

## Fișiere ignorate

Fișierele obiect (`*.o`, `*.obj`) și executabilele (`*.exe`) sunt generate la build și sunt ignorate de git prin `.gitignore`.
