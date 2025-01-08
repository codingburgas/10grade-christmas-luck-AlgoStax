#include "muscularSystem.h"

int muscularSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Muscular System");

    Texture2D muscularInfoScreen = LoadTexture("../assets/backgrounds/muscleSystemInfo.png");
    Texture2D armsInfoScreen = LoadTexture("../assets/backgrounds/armInfo.png");
    Texture2D chestInfoScreen = LoadTexture("../assets/backgrounds/chestInfo.png");
    Texture2D absInfoScreen = LoadTexture("../assets/backgrounds/abInfo.png");
    Texture2D legsInfoScreen = LoadTexture("../assets/backgrounds/legInfo.png");

    Texture2D currentBackground = muscularInfoScreen;

    const char* facts[] = {
        "The human body has over 600 muscles that enable movement and stability.",
        "Skeletal muscles are the only muscles we can control voluntarily.",
        "Muscles can contract and relax, generating force to move bones.",
        "The strongest muscle based on size is the **masseter** (jaw muscle).",
        "Muscles make up about 40% of a person’s body weight.",
        "Cardiac muscles, found in the heart, contract continuously without tiring."
    };

    Rectangle arms1 = { 180, 120, 120, 20 };
    Rectangle arms2 = { 720, 180, 130, 20 };
    Rectangle arms3 = { 700, 150, 130, 20 };
    Rectangle arms4 = { 680, 220, 130, 20 };
    Rectangle arms5 = { 720, 260, 130, 20 };
    Rectangle arms6 = { 695, 295, 160, 20 };

    Rectangle chest = { 160, 160, 160, 20 };

    Rectangle abs1 = { 170, 200, 160, 20 };
    Rectangle abs2 = { 220, 230, 120, 50 };
    
    
    Rectangle legs1 = { 240, 310, 110, 20 };
    Rectangle legs2 = { 240, 350, 110, 20 };
    Rectangle legs3 = { 200, 390, 130, 20 };
    Rectangle legs4 = { 200, 430, 130, 20 };
    Rectangle legs5 = { 200, 455, 130, 20 };
    Rectangle legs6 = { 210, 490, 130, 20 };
    Rectangle legs7 = { 680, 320, 110, 20 };
    Rectangle legs8 = { 670, 345, 160, 20 };
    Rectangle legs9 = { 670, 370, 80, 20 };
    Rectangle legs10 = { 670, 400, 120, 20 };
    Rectangle legs11 = { 650, 450, 100, 50 };
    Rectangle legs12 = { 330, 535, 130, 20 };

    bool isArms = false;
    bool isChest = false;
    bool isAbs = false;
    bool isLegs = false;

    int currentDialogIndex = 0;
    bool showDialog = true;
    bool goBack = false;

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

        if (CheckCollisionPointRec(mousePosition, arms1) || CheckCollisionPointRec(mousePosition, arms2) || CheckCollisionPointRec(mousePosition, arms3) || 
            CheckCollisionPointRec(mousePosition, arms4) || CheckCollisionPointRec(mousePosition, arms5) || CheckCollisionPointRec(mousePosition, arms6))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            {
                isArms = true; 
            }
        }

        else if (CheckCollisionPointRec(mousePosition, chest))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isChest = true;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, abs1) || CheckCollisionPointRec(mousePosition, abs2))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isAbs = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, legs1) || CheckCollisionPointRec(mousePosition, legs2) ||
             CheckCollisionPointRec(mousePosition, legs3) || CheckCollisionPointRec(mousePosition, legs4) || 
            CheckCollisionPointRec(mousePosition, legs5) || CheckCollisionPointRec(mousePosition, legs6) || 
            CheckCollisionPointRec(mousePosition, legs7) || CheckCollisionPointRec(mousePosition, legs8) || 
            CheckCollisionPointRec(mousePosition, legs9) || CheckCollisionPointRec(mousePosition, legs10) || 
            CheckCollisionPointRec(mousePosition, legs11) || CheckCollisionPointRec(mousePosition, legs12))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isLegs = true;
            }
        }

        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (isArms == true)
        {
            currentBackground = armsInfoScreen;
            isArms = false;
            goBack = true;
        }
        
        if (isChest == true)
        {
            currentBackground = chestInfoScreen;
            isChest = false;
            goBack = true;
        }

        if (isAbs == true)
        {
            currentBackground = absInfoScreen;
            isAbs = false;
            goBack = true;
        }

        if (isLegs == true)
        {
            currentBackground = legsInfoScreen;
            isLegs = false;
            goBack = true;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = muscularInfoScreen;
            goBack = false;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            CloseWindow();
            main();
        }

        EndDrawing();
    }
   
    UnloadTexture(muscularInfoScreen);
    UnloadTexture(absInfoScreen);
    UnloadTexture(chestInfoScreen);
    UnloadTexture(armsInfoScreen);
    UnloadTexture(legsInfoScreen);
    
    CloseWindow();

    return 0;
}
