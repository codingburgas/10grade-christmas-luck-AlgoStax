#include "cardiovascularSystem.h"

#include "organSystem.h"

int cardiovascularSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Organ System");

    Texture2D organInfoScreen = LoadTexture("../assets/backgrounds/organsSystemInfo.png");
    Texture2D liverInfoScreen = LoadTexture("../assets/backgrounds/liverInfo.png");
    Texture2D brainInfoScreen = LoadTexture("../assets/backgrounds/brainInfo.png");
    Texture2D heartInfoScreen = LoadTexture("../assets/backgrounds/heartInfo.png");
    Texture2D stomachInfoScreen = LoadTexture("../assets/backgrounds/stomachInfo.png");
    Texture2D colonInfoScreen = LoadTexture("../assets/backgrounds/colon.png");
    Texture2D smallIntestineInfoScreen = LoadTexture("../assets/backgrounds/smallIntestine.png");

    Texture2D currentBackground = organInfoScreen;

    const char* facts[] = {
        "Brain: Your brain generates enough power to light a bulb!",
        "Kidneys: Kidneys filter 50 gallons of blood daily!",
        "Stomach: Your stomach acid can dissolve metal!",
        "Heart and Lungs: Your heart beats over 100,000 times daily!",
        "Liver: Your liver can regenerate itself after damage!",
        "Small Intestine: Small intestines are 20 feet long—hardly small!"
    };

    Rectangle liver = { 320, 220, 60, 20 };
    Rectangle heart = { 320, 190, 70, 20 };
    Rectangle lungs = { 700, 150, 70, 20 };
    Rectangle brain = { 645, 50, 70, 20 };
    Rectangle stomach = { 710, 200, 80, 20 };
    Rectangle intestine = { 720, 275, 120, 20 };
    Rectangle colon = { 700, 250, 80, 20 };


    bool isLiver = false;
    bool isBrain = false;
    bool isStomach = false;
    bool isHeart = false;
    bool isColon = false;
    bool isIntestine = false;

    int currentDialogIndex = 0;
    bool showDialog = true;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (showDialog)
        {
            if (IsKeyPressed(KEY_D))
            {
                currentDialogIndex++;
            }
        }

        if (currentDialogIndex >= (sizeof(facts) / sizeof(facts[0])))
        {
            showDialog = false;
        }


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

        if (showDialog && currentDialogIndex < (sizeof(facts) / sizeof(facts[0])))
        {
            DrawRectangle(130, screenHeight - 100, screenWidth - 250, 70, Fade(BLACK, 0.8f));
            DrawText(facts[currentDialogIndex], 140, screenHeight - 85, 20, WHITE);
        }

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

        else if (CheckCollisionPointRec(mousePosition, intestine))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isIntestine = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, colon))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isColon = true;
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

        if (isColon == true)
        {
            currentBackground = colonInfoScreen;
            isColon = false;
        }

        if (isIntestine == true)
        {
            currentBackground = smallIntestineInfoScreen;
            isIntestine = false;
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
    UnloadTexture(colonInfoScreen);
    UnloadTexture(smallIntestineInfoScreen);

    CloseWindow();

    return 0;
}
