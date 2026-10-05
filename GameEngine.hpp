#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

class GameEngine
{
private:
    char board[3][3];
    char currentPlayer;

public:
    GameEngine();
    void reset();
    char getCell(int row, int col) const;
    char getCurrentPlayer() const;
    bool isValidMove(int row, int col) const;
    bool makeMove(int row, int col);
    char checkWinner() const;
    bool isBoardFull() const;
    bool isGameOver() const;
};

#endif
