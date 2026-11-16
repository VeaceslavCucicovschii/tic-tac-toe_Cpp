#ifndef MOVE_HPP
#define MOVE_HPP

#include <iostream>

// O mutare jucata: cine a jucat si unde (rand, coloana de la 0)
struct Move
{
    char player = ' ';
    int row = 0;
    int col = 0;

    // Folosit de std::sort: comparam dupa rand, apoi dupa coloana
    bool operator<(const Move &other) const
    {
        if (row != other.row)
        {
            return row < other.row;
        }
        return col < other.col;
    }
};

// Afisare: de ex.  X (1,2)  (numerotare de la 1, ca la jucator)
inline std::ostream &operator<<(std::ostream &out, const Move &m)
{
    out << m.player << " (" << m.row + 1 << "," << m.col + 1 << ")";
    return out;
}

#endif