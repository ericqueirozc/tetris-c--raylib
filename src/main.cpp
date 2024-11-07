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
    InitWindow(500, 620, "A New Window");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {

        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, );
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}