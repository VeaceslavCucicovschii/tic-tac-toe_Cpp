#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

// Motorul de joc: tine tabla, jucatorul curent si regulile jocului
class GameEngine {
private:
    char board[3][3];   // tabla de joc: 'X', 'O' sau ' ' (gol)
    char currentPlayer; // jucatorul curent: 'X' sau 'O'

public:
    GameEngine();

    // Reseteaza jocul: tabla goala, X incepe
    void reset();

    // Returneaza simbolul aflat pe o celula
    char getCell(int row, int col) const;

    // Returneaza jucatorul curent
    char getCurrentPlayer() const;

    // Verifica daca o mutare este valida
    bool isValidMove(int row, int col) const;

    // Pune simbolul jucatorului curent pe tabla si schimba randul
    bool makeMove(int row, int col);

    // Verifica daca exista un castigator. Returneaza 'X', 'O' sau ' ' (niciunul)
    char checkWinner() const;

    // Verifica daca tabla este plina (remiza, daca nu exista castigator)
    bool isBoardFull() const;

    // Jocul s-a terminat daca exista castigator sau tabla e plina
    bool isGameOver() const;
};

#endif
