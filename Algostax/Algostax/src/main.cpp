#include "raylib.h"

int main(void)
{
    const int screenWidth = 1024;
    const int screenHeight = 1024;
    InitWindow(screenWidth, screenHeight, "Algostax");

    Texture2D backgroundTexture = LoadTexture("../assets/backgrounds/clinic-background.png");

    Texture2D backFrames[2];
    backFrames[0] = LoadTexture("../assets/doctor/back-walk1.png");
    backFrames[1] = LoadTexture("../assets/doctor/back-walk2.png");

    Texture2D sideFrames[2];
    sideFrames[1] = LoadTexture("../assets/doctor/side-walk1.png");
    sideFrames[0] = LoadTexture("../assets/doctor/side-walk2.png");

    Texture2D frontFrames[2];
    frontFrames[0] = LoadTexture("../assets/doctor/front-walk1.png");
    frontFrames[1] = LoadTexture("../assets/doctor/front-walk2.png");

    Texture2D doctorFront = LoadTexture("../assets/doctor/doctor-front.png");

    int totalFrames = 2;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    const float frameSpeed = 0.4f;

    Vector2 doctorPos = { -485, -900 };
    float speed = 100.0f;
    bool isMoving = false;
    Vector2 velocity = { 0.0f, 0.0f };

    float initiMovementTimer = 0.0f;
    const float initMovementDuration = 1.0f;

    float scale = 0.2f;

    int targetWidth = (int)(backFrames[0].width * scale);
    int targetHeight = (int)(backFrames[0].height * scale);

    int standingWidth = (int)(doctorFront.width * scale);
    int standingHeight = (int)(doctorFront.height * scale);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (initiMovementTimer < initMovementDuration)
        {
            velocity = Vector2{ 0.0f, speed };

            frameTimer += deltaTime;
            if (frameTimer >= frameSpeed)
            {
                frameTimer = 0.0f;
                currentFrame++;
                if (currentFrame >= totalFrames) currentFrame = 0;
            }

            initiMovementTimer += deltaTime;
        }
        else
        {
            if (IsKeyDown(KEY_S))
            {
                velocity = Vector2{ 0.0f, -speed };
                isMoving = true;
            }
            else if (IsKeyDown(KEY_W))
            {
                velocity = Vector2{ 0.0f, speed };
                isMoving = true;
            }
            else if (IsKeyDown(KEY_D))
            {
                velocity = Vector2{ -speed, 0.0f };
                isMoving = true;
            }
            else if (IsKeyDown(KEY_A))
            {
                velocity = Vector2{ speed, 0.0f };
                isMoving = true;
            }
            else
            {
                velocity = Vector2{ 0.0f, 0.0f };
                isMoving = false;
            }
        }

        doctorPos.x += velocity.x * deltaTime;
        doctorPos.y += velocity.y * deltaTime;

        if (isMoving)
        {
            frameTimer += deltaTime;
            if (frameTimer >= frameSpeed)
            {
                frameTimer = 0.0f;
                currentFrame++;
                if (currentFrame >= totalFrames) currentFrame = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(backgroundTexture, 0, 0, WHITE);

        if (initiMovementTimer < initMovementDuration)
        {
            DrawTexturePro(backFrames[currentFrame],
                Rectangle{ 0, 0, (float)backFrames[0].width, (float)backFrames[0].height },
                Rectangle{ 0, 0, (float)targetWidth, (float)targetHeight },
                doctorPos, 0.0f, WHITE);
        }
        else if (isMoving)
        {
            if (velocity.y > 0)
            {
                DrawTexturePro(backFrames[currentFrame],
                    Rectangle{ 0, 0, (float)backFrames[0].width, (float)backFrames[0].height },
                    Rectangle{ 0, 0, (float)targetWidth, (float)targetHeight },
                    doctorPos, 0.0f, WHITE);
            }
            else if (velocity.y < 0)
            {
                DrawTexturePro(frontFrames[currentFrame],
                    Rectangle{ 0, 0, (float)frontFrames[0].width, (float)frontFrames[0].height },
                    Rectangle{ 0, 0, (float)targetWidth, (float)targetHeight },
                    doctorPos, 0.0f, WHITE);
            }
            else if (velocity.x < 0)
            {
                DrawTexturePro(sideFrames[0],
                    Rectangle{ 0, 0, (float)sideFrames[0].width, (float)sideFrames[0].height },
                    Rectangle{ 0, 0, (float)targetWidth, (float)targetHeight },
                    doctorPos, 0.0f, WHITE);
            }
            else if (velocity.x > 0)
            {
                DrawTexturePro(sideFrames[1],
                    Rectangle{ 0, 0, (float)sideFrames[1].width, (float)sideFrames[1].height },
                    Rectangle{ 0, 0, (float)targetWidth, (float)targetHeight },
                    doctorPos, 0.0f, WHITE);
            }
        }
        else
        {
            DrawTexturePro(doctorFront,
                Rectangle{ 0, 0, (float)doctorFront.width, (float)doctorFront.height },
                Rectangle{ 0, 0, (float)standingWidth, (float)standingHeight },
                doctorPos, 0.0f, WHITE);
        }

        EndDrawing();
    }

    UnloadTexture(backgroundTexture);
    UnloadTexture(doctorFront);
    for (int i = 0; i < 2; i++)
    {
        UnloadTexture(backFrames[i]);
        UnloadTexture(sideFrames[i]);
        UnloadTexture(frontFrames[i]);
    }

    CloseWindow();

    return 0;
}
