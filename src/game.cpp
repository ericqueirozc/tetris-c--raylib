#include "game.h"
#include "blocks.cpp"
#include <iostream>
using namespace std;

Game::Game()
{

    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
};

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::HandleInput()
{
    // cout << "left";
    int keyPressed = GetKeyPressed();
    // cout << "left";
    switch (keyPressed)
    {
    case KEY_A:
        cout << "left";
        MoveBlockLeft();
        cout << "left";
        break;
    case KEY_D:
        MoveBlockRight();
        cout << "right";
        break;
    case KEY_S:
        MoveBlockDown();
        cout << "down";
        break;
    case KEY_W:
        RotateBlock();
    }
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (IsBlockOutside())
    {
        currentBlock.Move(0, 1);
    }
}
void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsBlockOutside())
    {
        currentBlock.Move(0, -1);
    }
}
void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if (IsBlockOutside())
    {
        currentBlock.Move(-1, 0);
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if (IsBlockOutside())
    {
        currentBlock.UndoRotation();
    }
}
