#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "IRenderer.hpp"

class Renderer : public IRenderer
{
public:
    void drawBoard(const GameEngine &engine);
    void drawWelcome();
    void drawTurn(char player);
    void drawInvalidMove();
    void drawResult(char winner);
    void drawMoves(const std::vector<Move> &moves);
};

#endif