#include "Listener.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool Listener::getMove(int &row, int &col)
{
    std::string line;
    if (!std::getline(std::cin, line))
    {
        return false; // s-a terminat intrarea
    }

    // Citim cele doua numere din linie cu un flux de intrare din text
    std::istringstream stream(line);
    if (!(stream >> row >> col))
    {
        row = -1; // date gresite -> mutare invalida
        col = -1;
        return true;
    }
    row--; // trecem la numerotarea de la 0
    col--;
    return true;
}