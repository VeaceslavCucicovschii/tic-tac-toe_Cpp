#ifndef LISTENER_HPP
#define LISTENER_HPP

// Ascultatorul: se ocupa doar de citirea input-ului de la utilizator
class Listener {
public:
    // Citeste randul si coloana alese de jucator
    static void getMove(int& row, int& col);
};

#endif
