#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include <vector>
#include "GameEngine.hpp"

// Clasa abstracta (are functii cu "= 0")
class IRenderer
{
public:
    virtual ~IRenderer() {}

    virtual void drawBoard(const GameEngine &engine) = 0;
    virtual void drawWelcome() = 0;
    virtual void drawTurn(char player) = 0;
    virtual void drawInvalidMove() = 0;
    virtual void drawResult(char winner) = 0;
    virtual void drawMoves(const std::vector<Move> &moves) = 0;
};

#endif