#include "raylib.h"

struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;

    void Draw()
    {
        DrawCircle((int) x, (int) y, radius, WHITE);
    }
};

struct Paddle
{
    float x, y;
    float speed;
    float width, height;

    void Draw()
    {
        DrawRectangle(x - width / 2, y - height / 2, width, height, WHITE);
    }
};


int main(){
    InitWindow(800, 600, "Pong");
    // Set refresh rate for my monitor
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;
    // Get screen width + height & divide by 2. 2.0f helps DrawCircle method to read as int
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    // Set Radius at 5
    ball.radius = 5;
    // Set ball_speed variables
    ball.speedX = 100;
    ball.speedY = 300;

    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;

    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;

    while (!WindowShouldClose()){
        // take ball.x and add some motion to it. Multiply GetFrameTime() to speed up ball motion in relation to the monitor's speed.
        ball.x += ball.speedX * GetFrameTime();
        // same to ball.y
        ball.y += ball.speedY * GetFrameTime();
        // Set ball to bounce off top of screen
        if (ball.y < 0){
            ball.y = 0;
            ball.speedY *= -1;
        }
        // If ball.y is greater than screen height (The top of the screen)
        if(ball.y > GetScreenHeight()){
            // Set ball.y equal to screen height to stop ball from sticking to bottom of the screen
            ball.y = GetScreenHeight();
            // Then reverse the ball.speedY direction, multiply ball.speedY by -1
            ball.speedY *= -1; 
        }


        BeginDrawing();
            ClearBackground(BLACK);
            // Draw circle , Colour object WHITE
            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();
            // Draw Frames per second
            DrawFPS(10, 10);
        EndDrawing();
    }
}