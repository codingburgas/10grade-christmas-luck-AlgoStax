#include "cardiovascularSystem.h"

int cardiovascularSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Cardiovascular System");

    Texture2D cardiovascularInfoScreen = LoadTexture("../assets/backgrounds/cardiovascularSystemScreen.png");
    Texture2D kidneyInfoScreen = LoadTexture("../assets/backgrounds/kidneyInfo.png");
    Texture2D capillariesInfoScreen = LoadTexture("../assets/backgrounds/capillariesInfo.png");
    Texture2D heartInfoScreen = LoadTexture("../assets/backgrounds/cardiovascularHeartInfo.png");
    Texture2D veinsInfoScreen = LoadTexture("../assets/backgrounds/veinsInfo.png");
    

    Texture2D currentBackground = cardiovascularInfoScreen;

    const char* facts[] = {
        "The heart beats 100,000 times daily to circulate blood.",
        "Blood vessels stretch over 60,000 miles, circling Earth twice.",
        "The heart generates its own electrical impulses to beat.",
        "Cardiac muscles contract nonstop without tiring.",
        "Most arteries carry oxygen-rich blood; the pulmonary artery doesn’t.",
        "Blood flow adjusts to supply organs during activity."
    };

    Rectangle kidney = { 510, 320, 60, 20 };
    Rectangle capillaries = { 280, 385, 170, 20 };
    Rectangle heart = { 620, 230, 270, 20 };
    Rectangle veins = { 620, 190, 270, 20 };

    bool isKidney = false;
    bool isCapillaries = false;
    bool isHeart = false;
    bool isVeins = false;
    bool goBack = false;
    

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

        if (goBack == true) {
        DrawText("< Press 'SPACE' to go back", 20, 10, 10, GRAY);
        }

        if (goBack == false)
        {
            DrawText("< Press 'ENTER' to go back", 20, 10, 10, GRAY);
        }

        if (showDialog && currentDialogIndex < (sizeof(facts) / sizeof(facts[0])))
        {
            DrawRectangle(130, screenHeight - 100, screenWidth - 250, 70, Fade(BLACK, 0.8f));
            DrawText(facts[currentDialogIndex], 140, screenHeight - 85, 20, WHITE);
            DrawText("Press 'D' to continue", 850, screenHeight - 55, 10, GRAY);
        }

        if (CheckCollisionPointRec(mousePosition, kidney))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isKidney = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, capillaries))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isCapillaries = true;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, heart))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isHeart = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, heart) || CheckCollisionPointRec(mousePosition, veins))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isVeins = true;
            }
        }

        

        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (isKidney == true)
        {
            currentBackground = kidneyInfoScreen;
            isKidney = false;
            goBack = true;
        }

        if (isCapillaries == true)
        {
            currentBackground = capillariesInfoScreen;
            isCapillaries = false;
            goBack = true;
        }

        if (isHeart == true)
        {
            currentBackground = heartInfoScreen;
            isHeart = false;
            goBack = true;
        }


        if (isVeins == true)
        {
            currentBackground = veinsInfoScreen;
            isVeins = false;
            goBack = true;
        }


        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = cardiovascularInfoScreen;
            goBack = false;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            CloseWindow();
            main();
        }

        EndDrawing();
    }

    UnloadTexture(kidneyInfoScreen);
    UnloadTexture(capillariesInfoScreen);
    UnloadTexture(veinsInfoScreen);
    UnloadTexture(heartInfoScreen);

    CloseWindow();

    return 0;
}
