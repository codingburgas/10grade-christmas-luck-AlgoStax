#include "cardiovascularSystem.h"

#include "organSystem.h"

int cardiovascularSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Cardiovascular System");

    Texture2D cardiovascularInfoScreen = LoadTexture("../assets/backgrounds/cardiovascularSystem.png");
    Texture2D kidneyInfoScreen = LoadTexture("../assets/backgrounds/kidneyInfo.png");
    Texture2D capillariesInfoScreen = LoadTexture("../assets/backgrounds/capillariesInfo.png");
    Texture2D heartInfoScreen = LoadTexture("../assets/backgrounds/cardiovascularHeartInfo.png");
    Texture2D veinsInfoScreen = LoadTexture("../assets/backgrounds/veinsInfo.png");
    

    Texture2D currentBackground = cardiovascularInfoScreen;

    const char* facts[] = {
        "Brain: Your brain generates enough power to light a bulb!",
        "Kidneys: Kidneys filter 50 gallons of blood daily!",
        "Stomach: Your stomach acid can dissolve metal!",
        "Heart and Lungs: Your heart beats over 100,000 times daily!",
        "Liver: Your liver can regenerate itself after damage!",
        "Small Intestine: Small intestines are 20 feet long—hardly small!"
    };

    Rectangle kidney = { 510, 320, 60, 20 };
    Rectangle capillaries = { 280, 385, 170, 20 };
    Rectangle heart = { 620, 230, 270, 20 };
    Rectangle veins = { 620, 190, 270, 20 };
    


    bool isKidney = false;
    bool isCapillaries = false;
    bool isHeart = false;
    bool isVeins = false;
    

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
        }

        if (isCapillaries == true)
        {
            currentBackground = capillariesInfoScreen;
            isCapillaries = false;
        }

        if (isHeart == true)
        {
            currentBackground = heartInfoScreen;
            isHeart = false;
        }


        if (isVeins == true)
        {
            currentBackground = veinsInfoScreen;
            isVeins = false;
        }


        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = cardiovascularInfoScreen;
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
