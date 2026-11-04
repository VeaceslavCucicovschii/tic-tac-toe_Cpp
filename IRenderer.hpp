#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "GameEngine.hpp"

// 7. Clasa abstracta = o clasa cu cel putin o functie "= 0".
//    Din ea NU poti crea obiecte; ea doar spune ce functii trebuie sa aiba
//    clasele care o mostenesc (aici: Renderer).
class IRenderer
{
public:
    virtual ~IRenderer() {} // necesar la clasele cu functii virtuale

    virtual void drawBoard(const GameEngine &engine) = 0;
    virtual void drawWelcome() = 0;
    virtual void drawTurn(char player) = 0;
    virtual void drawInvalidMove() = 0;
    virtual void drawResult(char winner) = 0;
};

#endif