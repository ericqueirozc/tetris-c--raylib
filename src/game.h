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

private:
    bool IsBlockOutside();
    void RotateBlock();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};