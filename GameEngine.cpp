#include "GameEngine.hpp"
#include <algorithm> // std::copy, std::equal, std::find, std::fill
#include <iterator>  // std::back_inserter

GameEngine::GameEngine()
{
    reset();
}

GameEngine::GameEngine(char player)
{
    reset();
    currentPlayer = player;
}

GameEngine::GameEngine(const GameEngine &other)
{
    copyFrom(other);
}

GameEngine &GameEngine::operator=(const GameEngine &other)
{
    copyFrom(other);
    return *this;
}

// Copiem cu algoritmul std::copy
void GameEngine::copyFrom(const GameEngine &other)
{
    std::copy(other.board.begin(), other.board.end(), board.begin());
    currentPlayer = other.currentPlayer;
    history.clear();
    std::copy(other.history.begin(), other.history.end(), std::back_inserter(history));
}

// Comparam cu algoritmul std::equal
bool GameEngine::operator==(const GameEngine &other) const
{
    bool sameBoard = std::equal(board.begin(), board.end(), other.board.begin());
    return sameBoard && currentPlayer == other.currentPlayer;
}

void GameEngine::reset()
{
    std::fill(board.begin(), board.end(), ' ');
    currentPlayer = 'X';
    history.clear();
}

char GameEngine::getCell(int row, int col) const
{
    return board[row * 3 + col];
}

char GameEngine::getCurrentPlayer() const
{
    return currentPlayer;
}

bool GameEngine::isValidMove(int row, int col) const
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        return false;
    }
    return board[row * 3 + col] == ' ';
}

bool GameEngine::makeMove(int row, int col)
{
    if (isGameOver() || !isValidMove(row, col))
    {
        return false;
    }

    board[row * 3 + col] = currentPlayer;

    Move m;
    m.player = currentPlayer;
    m.row = row;
    m.col = col;
    history.push_back(m);

    if (!isGameOver())
    {
        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
    return true;
}

char GameEngine::checkWinner() const
{
    // Toate liniile castigatoare (pozitii in tabla de 9 celule)
    const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // randuri
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // coloane
        {0, 4, 8},
        {2, 4, 6}}; // diagonale

    for (int i = 0; i < 8; i++)
    {
        char a = board[lines[i][0]];
        char b = board[lines[i][1]];
        char c = board[lines[i][2]];
        if (a != ' ' && a == b && b == c)
        {
            return a;
        }
    }
    return ' ';
}

// Cautam o celula goala cu algoritmul std::find
bool GameEngine::isBoardFull() const
{
    return std::find(board.begin(), board.end(), ' ') == board.end();
}

bool GameEngine::isGameOver() const
{
    return checkWinner() != ' ' || isBoardFull();
}

const std::vector<Move> &GameEngine::getHistory() const
{
    return history;
}

// Format: 9 celule (X, O sau .) si jucatorul curent
void GameEngine::print(std::ostream &out) const
{
    for (char c : board)
    {
        if (c == ' ')
        {
            out << '.';
        }
        else
        {
            out << c;
        }
        out << ' ';
    }
    out << currentPlayer;
}

void GameEngine::read(std::istream &in)
{
    for (char &c : board)
    {
        in >> c;
        if (c == '.')
        {
            c = ' ';
        }
    }
    in >> currentPlayer;
    history.clear();
}