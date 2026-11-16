#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <array>
#include <vector>
#include <iostream>
#include "Move.hpp"

class GameEngine
{
private:
    std::array<char, 9> board; // tabla 3x3 ca un singur sir de 9 celule (std::array)
    char currentPlayer;
    std::vector<Move> history; // mutarile jucate (std::vector)

    void copyFrom(const GameEngine &other); // ajutor pentru copiere

public:
    GameEngine();
    GameEngine(char player);
    GameEngine(const GameEngine &other);
    GameEngine &operator=(const GameEngine &other);
    bool operator==(const GameEngine &other) const;

    void reset();
    char getCell(int row, int col) const;
    char getCurrentPlayer() const;
    bool isValidMove(int row, int col) const;
    bool makeMove(int row, int col);
    char checkWinner() const;
    bool isBoardFull() const;
    bool isGameOver() const;
    const std::vector<Move> &getHistory() const;

    void print(std::ostream &out) const;
    void read(std::istream &in);
};

inline std::ostream &operator<<(std::ostream &out, const GameEngine &game)
{
    game.print(out);
    return out;
}

inline std::istream &operator>>(std::istream &in, GameEngine &game)
{
    game.read(in);
    return in;
}

#endif