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
            // Draw Left Paddle Rectangle, Subtract half of screen height (2 - 50) to center paddle position on Y axis
            DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
            // Draw Right Paddle Rectangle, Subtract half of screen height (2 - 50) to center paddle position on Y axis
            // DrawRectangle(740, GetScreenHeight() /2 - 50, 10, 100, WHITE);
            // Draw Right Paddle Rectangle, Get screen width subtract by 50 and 10 
            DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
            // Draw Frames per second
            DrawFPS(10, 10);
        EndDrawing();
    }
}