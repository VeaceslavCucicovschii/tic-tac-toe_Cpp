#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <iostream>

class GameEngine
{
private:
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // tabla goala
    char currentPlayer = 'X';                                               // incepe X

public:
    // 1. Constructor implicit - este scris in GameEngine.cpp (e gol).
    //    Valorile de mai sus (tabla goala si 'X') se pun singure.
    GameEngine();

    // 3. Constructor cu parametri - primim jucatorul care incepe
    GameEngine(char player)
    {
        currentPlayer = player;
    }

    // 2. Constructor de copiere - copiem celula cu celula din alt joc
    GameEngine(const GameEngine &other)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = other.board[i][j];
            }
        }
        currentPlayer = other.currentPlayer;
    }

    // 4. Operator de atribuire (a = b) - la fel, copiem tot
    GameEngine &operator=(const GameEngine &other)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = other.board[i][j];
            }
        }
        currentPlayer = other.currentPlayer;
        return *this; // returnam obiectul curent
    }

    // 5. Operator de comparare (a == b)
    bool operator==(const GameEngine &other) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != other.board[i][j])
                {
                    return false; // am gasit o diferenta
                }
            }
        }
        if (currentPlayer != other.currentPlayer)
        {
            return false;
        }
        return true; // totul este la fel
    }

    // Scrie jocul in "out" (de ex. pe ecran): 9 celule si jucatorul curent
    // Celula goala se scrie ca punct '.'
    void print(std::ostream &out) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    out << '.';
                }
                else
                {
                    out << board[i][j];
                }
                out << ' ';
            }
        }
        out << currentPlayer;
    }

    // Citeste jocul din "in" (de ex. de la tastatura), in acelasi format
    void read(std::istream &in)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char c;
                in >> c;
                if (c == '.')
                {
                    board[i][j] = ' ';
                }
                else
                {
                    board[i][j] = c;
                }
            }
        }
        in >> currentPlayer;
    }

    // Aceste metode sunt scrise in GameEngine.cpp
    void reset();
    char getCell(int row, int col) const;
    char getCurrentPlayer() const;
    bool isValidMove(int row, int col) const;
    bool makeMove(int row, int col);
    char checkWinner() const;
    bool isBoardFull() const;
    bool isGameOver() const;
};

// 6. Operatorul << : permite scrierea  cout << joc;
//    Doar apeleaza print() de mai sus.
inline std::ostream &operator<<(std::ostream &out, const GameEngine &game)
{
    game.print(out);
    return out;
}

// 6. Operatorul >> : permite citirea  cin >> joc;
inline std::istream &operator>>(std::istream &in, GameEngine &game)
{
    game.read(in);
    return in;
}

#endif