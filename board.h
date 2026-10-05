#pragma once

struct Board
{
    char cells[3][3];

    void reset();
    bool place(int row, int col, char symbol);
    char checkWinner() const;
    bool isFull() const;
    void print() const;
};