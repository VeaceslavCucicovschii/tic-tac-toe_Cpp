# Tic Tac Toe (X și 0)

## 1. Denumirea proiectului

**Tic Tac Toe** — implementare simplă în C++, joc de consolă pentru doi jucători.

## 2. Descrierea proiectului / reguli de joc

Jocul se desfășoară pe o tablă de **3x3 celule**. Doi jucători, **X** și **O**, joacă pe rând, plasând simbolul lor într-o celulă liberă.

**Reguli:**
- Jucătorul **X** începe jocul.
- La fiecare tură, jucătorul curent alege un rând și o coloană (numerotate de la 1 la 3) unde vrea să plaseze simbolul.
- O mutare este validă doar dacă celula aleasă este liberă și coordonatele sunt în interiorul tablei.
- După fiecare mutare, rândul trece la celălalt jucător.
- **Câștigă** jucătorul care reușește să alinieze 3 simboluri identice pe orizontală, verticală sau diagonală.
- Dacă tabla se umple complet fără ca vreun jucător să alinieze 3 simboluri, jocul se termină **remiză**.
- Jocul se oprește automat imediat ce există un câștigător sau tabla e plină.

## 3. Structuri de date și descrierea lor

Proiectul este împărțit în trei componente independente, fiecare cu responsabilitatea ei, definite fiecare într-un fișier `.hpp` separat.

### `GameEngine.hpp` — Motorul de joc

Clasa `GameEngine` gestionează **starea și regulile** jocului. Este singura componentă care reține date:

| Membru | Tip | Descriere |
|---|---|---|
| `board` | `char[3][3]` | Tabla de joc; fiecare celulă conține `'X'`, `'O'` sau `' '` (goală) |
| `currentPlayer` | `char` | Jucătorul curent, `'X'` sau `'O'` |

**Metode principale:**
- `reset()` — inițializează tabla goală și pune `'X'` la rând
- `getCell(row, col)` — returnează simbolul dintr-o celulă
- `getCurrentPlayer()` — returnează jucătorul curent
- `isValidMove(row, col)` — verifică dacă o mutare este posibilă
- `makeMove(row, col)` — aplică mutarea și schimbă rândul
- `checkWinner()` — verifică liniile, coloanele și diagonalele; returnează câștigătorul sau `' '`
- `isBoardFull()` — verifică dacă mai există celule libere
- `isGameOver()` — verifică dacă jocul s-a încheiat (câștigător sau tablă plină)

Metodele nu sunt statice, deoarece fiecare operează pe datele (`board`, `currentPlayer`) ale unei instanțe specifice de joc.

### `Renderer.hpp` — Desenatorul

Clasa `Renderer` se ocupă exclusiv de **afișarea** informațiilor în consolă. Nu reține nicio stare proprie — primește tot ce are nevoie ca parametru la fiecare apel.

**Metode principale (toate `static`):**
- `drawBoard(const GameEngine& engine)` — desenează tabla curentă
- `drawWelcome()` — afișează mesajul de bun venit
- `drawTurn(char player)` — afișează a cui e tura
- `drawInvalidMove()` — afișează un mesaj de eroare pentru mutare invalidă
- `drawResult(char winner)` — afișează rezultatul final (câștigător sau remiză)

Metodele sunt statice pentru că nu depind de nicio dată proprie a clasei — sunt simple funcții utilitare grupate logic.

### `Listener.hpp` — Ascultătorul

Clasa `Listener` se ocupă exclusiv de **citirea input-ului** de la jucător. La fel ca `Renderer`, nu reține nicio stare.

**Metodă principală (`static`):**
- `getMove(int& row, int& col)` — citește de la tastatură rândul și coloana alese de jucător

### `main.cpp` — Punctul de intrare

Leagă cele trei componente într-o buclă de joc: cere mutarea prin `Listener`, o aplică prin `GameEngine`, apoi afișează rezultatul prin `Renderer`, repetând până când `GameEngine::isGameOver()` returnează `true`.
