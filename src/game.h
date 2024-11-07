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

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    void Restart();
    bool BlockFits();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};