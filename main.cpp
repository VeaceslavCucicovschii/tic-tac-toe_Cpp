#include <algorithm> // std::copy, std::sort
#include <iterator>
#include <memory> // std::unique_ptr, std::make_unique
#include <vector>
#include "Renderer.hpp"
#include "Listener.hpp"

int main()
{
    // smart pointers: se sterg singure, nu avem nevoie de new / delete
    std::unique_ptr<IRenderer> renderer = std::make_unique<Renderer>();
    std::unique_ptr<GameEngine> game = std::make_unique<GameEngine>();

    renderer->drawWelcome();
    while (!game->isGameOver())
    {
        renderer->drawBoard(*game);
        renderer->drawTurn(game->getCurrentPlayer());

        int row, col;
        if (!Listener::getMove(row, col))
        {
            return 0;
        }
        if (!game->makeMove(row, col))
        {
            renderer->drawInvalidMove();
        }
    }
    renderer->drawBoard(*game);
    renderer->drawResult(game->checkWinner());

    // Copiem mutarile (std::copy), apoi le sortam (std::sort)
    std::vector<Move> moves;
    const std::vector<Move> &history = game->getHistory(); // referinta, fara copie
    std::copy(history.begin(), history.end(), std::back_inserter(moves));
    std::sort(moves.begin(), moves.end());
    renderer->drawMoves(moves);

    return 0;
}