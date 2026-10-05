#include "GameEngine.hpp"

GameEngine::GameEngine()
{
}

void GameEngine::reset()
{
}

char GameEngine::getCell(int row, int col) const
{
    return ' ';
}

char GameEngine::getCurrentPlayer() const
{
    return ' ';
}

bool GameEngine::isValidMove(int row, int col) const
{
    return false;
}

bool GameEngine::makeMove(int row, int col)
{
    return false;
}

char GameEngine::checkWinner() const
{
    return ' ';
}

bool GameEngine::isBoardFull() const
{
    return false;
}

bool GameEngine::isGameOver() const
{
    return false;
}
