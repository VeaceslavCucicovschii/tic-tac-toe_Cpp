#ifndef LISTENER_HPP
#define LISTENER_HPP

class Listener
{
public:
    // Citeste o mutare. Returneaza false daca nu mai exista date de citit.
    // row si col sunt referinte: functia le modifica direct.
    static bool getMove(int &row, int &col);
};

#endif