#include "organSystem.h"

int organSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Organ System");

    Texture2D organInfoScreen = LoadTexture("../assets/backgrounds/organsSystemInfo.png");
    Texture2D liverInfoScreen = LoadTexture("../assets/backgrounds/liverInfo.png");
    Texture2D brainInfoScreen = LoadTexture("../assets/backgrounds/brainInfo.png");
    Texture2D heartInfoScreen = LoadTexture("../assets/backgrounds/heartInfo.png");
    Texture2D stomachInfoScreen = LoadTexture("../assets/backgrounds/stomachInfo.png");

    Texture2D currentBackground = organInfoScreen;

    Rectangle liver = { 320, 220, 60, 20 };
    Rectangle heart = { 320, 190, 70, 20 };
    Rectangle lungs = { 700, 150, 70, 20 };
    Rectangle brain = { 645, 50, 70, 20 };
    Rectangle stomach = { 700, 250, 80, 20 };
  

    bool isLiver = false;
    bool isBrain = false;
    bool isStomach = false;
    bool isHeart = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexturePro(
            currentBackground,
            Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height },
            Rectangle{ 0, 0, 1100, 620 },
            Vector2{ 0.0f, 0.0f },
            0.0f,
            WHITE);     

        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, liver))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isLiver = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, brain))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isBrain = true;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, stomach))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isStomach = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, heart) || CheckCollisionPointRec(mousePosition, lungs))


        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isHeart = true;
            }
        }

        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (isLiver == true)
        {
            currentBackground = liverInfoScreen;
            isLiver = false;
        }

        if (isBrain == true)
        {
            currentBackground = brainInfoScreen;
            isBrain = false;
        }

        if (isStomach == true)
        {
            currentBackground = stomachInfoScreen;
            isStomach = false;
        }

        if (isHeart == true)
        {
            currentBackground = heartInfoScreen;
            isHeart = false;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = organInfoScreen;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            CloseWindow();
            main();
        }

        EndDrawing();
    }

    UnloadTexture(brainInfoScreen);
    UnloadTexture(liverInfoScreen);
    UnloadTexture(stomachInfoScreen);
    UnloadTexture(heartInfoScreen);

    CloseWindow();

    return 0;
}
