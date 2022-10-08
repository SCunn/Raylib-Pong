#include "raylib.h"

int main(){
    InitWindow(800, 600, "Pong");
    // Set refresh rate for my monitor
    SetWindowState(FLAG_VSYNC_HINT);
    // Get screen width + height & divide by 2. 2.0f helps DrawCircle method to read as int
    float ball_X = GetScreenWidth() / 2.0f;
    float ball_Y = GetScreenHeight() / 2.0f;
    // Set Radius at 5
    float ball_radius = 5;
    // Set ball_speed variables
    float ball_speed_X = 300;
    float ball_speed_Y = 300;

    while (!WindowShouldClose()){
        // take ball_X and add some motion to it. Multiply GetFrameTime() to speed up ball motion in relation to the monitor's speed.
        ball_X += ball_speed_X * GetFrameTime();
        // same to ball_Y
        ball_Y += ball_speed_Y * GetFrameTime();
        // Set ball to bounce off top of screen
        if (ball_Y < 0){
            ball_Y = 0;
            ball_speed_Y *= -1;
        }
        // If ball_Y is greater than screen height (The top of the screen)
        if(ball_Y > GetScreenHeight()){
            // Set ball_Y equal to screen height to stop ball from sticking to bottom of the screen
            ball_Y = GetScreenHeight();
            // Then reverse the ball_speed_Y direction, multiply ball_speed_Y by -1
            ball_speed_Y *= -1; 
        }


        BeginDrawing();
            ClearBackground(BLACK);
            // Draw circle , Colour object WHITE
            DrawCircle((int)ball_X, (int)ball_Y, ball_radius, WHITE);
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