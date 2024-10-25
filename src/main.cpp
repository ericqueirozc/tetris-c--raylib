#include <raylib.h>
#include <raymath.h>
#include "view.h"
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    // View Viewport;
    InitWindow(300, 600, "A New Window");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {

        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}