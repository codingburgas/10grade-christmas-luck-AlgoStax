#include "pch.h"

int main(void)
{
    const int screenWidth = 1024;
    const int screenHeight = 1024;
    InitWindow(screenWidth, screenHeight, "Algostax");

    Texture2D backgroundTexture = LoadTexture("../assets/backgrounds/clinic-background.png");

    Texture2D backFrames[2];
    backFrames[0] = LoadTexture("../assets/doctor/back-walk1.png");
    backFrames[1] = LoadTexture("../assets/doctor/back-walk2.png");

    Texture2D leftFrames[2];
    leftFrames[0] = LoadTexture("../assets/doctor/side-walk1.png");
    leftFrames[1] = LoadTexture("../assets/doctor/right-walk1.png");

    Texture2D rightFrames[2];
    rightFrames[0] = LoadTexture("../assets/doctor/side-walk2.png");
    rightFrames[1] = LoadTexture("../assets/doctor/left-walk1.png");

    Texture2D frontFrames[2];
    frontFrames[0] = LoadTexture("../assets/doctor/front-walk1.png");
    frontFrames[1] = LoadTexture("../assets/doctor/front-walk2.png");

    Texture2D standingTexture = LoadTexture("../assets/doctor/doctor-front.png");

    int totalFrames = 2;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    const float frameSpeed = 0.4f;

    Vector2 characterPosition = { 485, 900 };
    float speed = 125.0f;
    bool isMoving = false;
    Vector2 velocity = { 0.0f, 0.0f };

    float scale = 0.2f;

    int targetWidth = (int)(backFrames[0].width * scale);
    int targetHeight = (int)(backFrames[0].height * scale);

    int standingWidth = (int)(standingTexture.width * scale);
    int standingHeight = (int)(standingTexture.height * scale);

    Rectangle medTable = { 470, 375, 95, 260 };
    Rectangle bed = { 810, 160, 100, 250 };
    Color transparentColor = { 100, 0, 0, 0 };

    Rectangle characterRect = { characterPosition.x, characterPosition.y, (float)targetWidth, (float)targetHeight };

    bool initialMoveNorth = true;
    float initialMoveDistance = 100.0f;
    float initialMoveSpeed = 50.0f;

    Rectangle screenBounds = { 90, 190, 840, 750 };

    
    Rectangle computerArea = { 730, 700, 100, 100 }; 
    bool interactionScreenActive = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        
        characterRect.x = characterPosition.x;
        characterRect.y = characterPosition.y;

        if (!interactionScreenActive)
        {
            UpdateCharacterMovement(characterPosition, velocity, characterRect,
                medTable, bed,computerArea, screenBounds, frameTimer,
                currentFrame, isMoving, initialMoveNorth,
                initialMoveDistance, initialMoveSpeed, deltaTime,
                speed, frameSpeed, totalFrames);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!interactionScreenActive)
        {
            DrawTexturePro(
                backgroundTexture,
                Rectangle{ 0, 0, (float)backgroundTexture.width, (float)backgroundTexture.height },
                Rectangle{ 0, 0, 1024, 1024 },
                Vector2{ 0.0f, 0.0f },
                0.0f,
                WHITE);

            if (isMoving || initialMoveNorth)
            {
                if (velocity.y < 0 || initialMoveNorth)
                {
                    DrawCharacterMovement(backFrames, currentFrame, characterPosition, targetWidth, targetHeight);
                }
                else if (velocity.y > 0)
                {
                    DrawCharacterMovement(frontFrames, currentFrame, characterPosition, targetWidth, targetHeight);
                }
                else if (velocity.x < 0)
                {
                    DrawCharacterMovement(leftFrames, currentFrame, characterPosition, targetWidth, targetHeight);
                }
                else if (velocity.x > 0)
                {
                    DrawCharacterMovement(rightFrames, currentFrame, characterPosition, targetWidth, targetHeight);
                }
            }
            else
            {
                DrawTexturePro(standingTexture, Rectangle{ 0, 0, (float)standingTexture.width, (float)standingTexture.height },
                    Rectangle{ characterPosition.x, characterPosition.y, (float)standingWidth, (float)standingHeight },
                    Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);
            }

            
            
            if (CheckCollisionRecs(characterRect, computerArea))
            {
                DrawText("Press E to interact", computerArea.x, computerArea.y - 20, 20, RED);
                if (IsKeyDown(KEY_E))
                {
                    interactionScreenActive = true;
                }
            }
        }
        else
        {
            
            ClearBackground(DARKGRAY);

            DrawText("Systems:", 400, 200, 40, WHITE);
            DrawText("1. Skeletal system", 400, 300, 30, WHITE);
            DrawText("2. Cardiovascular system", 400, 350, 30, WHITE);
            DrawText("3. Nervous system", 400, 400, 30, WHITE);
            DrawText("4. Muscles", 400, 450, 30, WHITE);
            DrawText("5. EXIT", 400, 500, 30, WHITE);

            if (IsKeyDown(KEY_FIVE)) 
            {
                interactionScreenActive = false;
            }
        }

        EndDrawing();
    }

    UnloadTexture(backgroundTexture);
    UnloadTexture(standingTexture);
    for (int i = 0; i < 2; i++)
    {
        UnloadTexture(backFrames[i]);
        UnloadTexture(leftFrames[i]);
        UnloadTexture(rightFrames[i]);
        UnloadTexture(frontFrames[i]);
    }

    CloseWindow();
}
