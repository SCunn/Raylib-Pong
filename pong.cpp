#include "raylib.h"

int main(){
    InitWindow(800, 600, "Pong");
    // Set refresh rate for my monitor
    SetWindowState(FLAG_VSYNC_HINT);

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            // Draw circle, Get screen width + height & divide by 2. Set Radius at 5, Colour object WHITE
            DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 5, WHITE);
            // Draw Frames per second
            DrawFPS(10, 10);
        EndDrawing();
    }
}