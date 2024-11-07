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
    gameOver = false;
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

    if (gameOver && keyPressed != 0)
    {
        Restart();
    }

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
    if (!gameOver)
    {

        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}
void Game::MoveBlockRight()
{
    if (!gameOver)
    {

        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}
void Game::MoveBlockDown()
{
    if (!gameOver)
    {

        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
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
    if (!gameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    // deixar marcado no grid a posição do bloco
    for (Position item : tiles)
    {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    // gera o proximo block
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
        return;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

void Game::Restart()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.col) == false)
        {
            return false;
        }
    }
    return true;
}
