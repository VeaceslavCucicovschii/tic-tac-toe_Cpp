#include "Renderer.hpp"
#include <iostream>
#include <string>

void Renderer::drawBoard(const GameEngine &engine)
{
    std::cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << " " << engine.getCell(i, 0) << " | " << engine.getCell(i, 1)
                  << " | " << engine.getCell(i, 2) << "\n";
        if (i < 2)
        {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << "\n";
}

void Renderer::drawWelcome()
{
    std::string text = "Tic Tac Toe - scrieti: rand coloana (1-3), ex: 2 2";
    std::cout << text << "\n";
}

void Renderer::drawTurn(char player)
{
    std::string text = "Joaca ";
    text = text + player + ": ";
    std::cout << text;
}

void Renderer::drawInvalidMove()
{
    std::string text = "Mutare invalida!";
    std::cout << text << "\n";
}

void Renderer::drawResult(char winner)
{
    std::string text;
    if (winner == ' ')
    {
        text = "Egalitate!";
    }
    else
    {
        text = "A castigat ";
        text += winner;
        text += "!";
    }
    std::cout << text << "\n";
}

void Renderer::drawMoves(const std::vector<Move> &moves)
{
    std::cout << "Mutarile (sortate): ";
    for (const Move &m : moves)
    {
        std::cout << m << "  ";
    }
    std::cout << "\n";
}