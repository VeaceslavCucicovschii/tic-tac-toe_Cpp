#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "IRenderer.hpp"

// ": public IRenderer" inseamna ca Renderer mosteneste clasa abstracta.
// Functiile de mai jos sunt scrise in Renderer.cpp.
class Renderer : public IRenderer
{
public:
    void drawBoard(const GameEngine &engine);
    void drawWelcome();
    void drawTurn(char player);
    void drawInvalidMove();
    void drawResult(char winner);
};

#endif