#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "GameEngine.hpp"

// Desenatorul: se ocupa doar de afisarea jocului pe ecran
class Renderer {
public:
    // Deseneaza tabla de joc curenta
    static void drawBoard(const GameEngine& engine);

    // Afiseaza mesajul de bun venit
    static void drawWelcome();

    // Afiseaza a cui e tura
    static void drawTurn(char player);

    // Afiseaza un mesaj de eroare pentru mutare invalida
    static void drawInvalidMove();

    // Afiseaza rezultatul final al jocului
    static void drawResult(char winner);
};

#endif
