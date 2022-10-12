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

    Rectangle GetRect()
    {
        return Rectangle { x - width / 2, y - height / 2, 10, 100 };
    }

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
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
    ball.speedX = 300;
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

        //  Left Paddle Controls
        if (IsKeyDown(KEY_W)){
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S)){
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }
        //  Right Paddle Controls
        if (IsKeyDown(KEY_UP)){
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN)){
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }

        // Left Paddle collison logic
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, leftPaddle.GetRect() ))
        { 
            // Keep ball from losing velocity on collision
            if (ball.speedX < 0)
            {
                ball.speedX *= -1.1f; // 1.1f speeds up the ball every time it is hit
                // determine how fast the ball moves when hit on the top or the bottom of the paddle 
                // Normalize the value between negative 1 & positive 1, then multiply by speedX of the ball
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX; 
            }
        }
        // Right Paddle collison logic
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, rightPaddle.GetRect() ))
        {
            // Keep ball from losing velocity on collision 
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1f; // 1.1f speeds up the ball every time it is hit
                // determine how fast the ball moves when hit on the top or the bottom of the paddle 
                // Normalize the value between negative 1 & positive 1, then multiply by speedX of the ball
                // Make ball.speedX negative on the right paddle
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * - ball.speedX;
            }
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