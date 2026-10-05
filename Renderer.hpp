#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "GameEngine.hpp"

class Renderer
{
public:
    static void drawBoard(const GameEngine &engine);
    static void drawWelcome();
    static void drawTurn(char player);
    static void drawInvalidMove();
    static void drawResult(char winner);
};

#endif
