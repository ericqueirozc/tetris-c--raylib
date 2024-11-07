#pragma once
#include "grid.h"
#include "bloc.h"

class Game
{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void HandleInput();
    void Draw();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;
    bool gameOver;
    int score;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    void Restart();
    bool BlockFits();
    void UpdateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};