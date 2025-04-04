#include "skeletalSystem.h"

int skeletalSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Skeletal System");

    Texture2D skeletalInfoScreen = LoadTexture("../assets/backgrounds/skeletalInfo.png");
    Texture2D armsInfoScreen = LoadTexture("../assets/backgrounds/skeletonArm.png");
    Texture2D chestInfoScreen = LoadTexture("../assets/backgrounds/chestBones.png");
    Texture2D absInfoScreen = LoadTexture("../assets/backgrounds/pelvicBone.png");
    Texture2D legsInfoScreen = LoadTexture("../assets/backgrounds/feetBone.png");

    Texture2D currentBackground = skeletalInfoScreen;

    const char* facts[] = {
        "The human body has 206 bones, which provide structure and support.",
        "Bones are constantly being remodeled, with new bone tissue replacing old tissue.",
        "The femur (thigh bone) is the longest and strongest bone in the body.",
        "The human skeleton accounts for about 15% of total body weight.",
        "The smallest bone in the body is the **stapes** bone in the ear.",
        "Bone marrow produces red and white blood cells."
    };

    Rectangle arms1 = { 230, 135, 120, 20 };
    Rectangle arms2 = { 720, 140, 130, 20 };
    Rectangle arms3 = { 700, 170, 130, 20 };
    Rectangle arms4 = { 680, 220, 130, 20 };
    Rectangle arms5 = { 720, 260, 130, 20 };
    Rectangle arms6 = { 695, 295, 160, 20 };

    Rectangle chest = { 160, 160, 160, 20 };

    Rectangle abs1 = { 175, 210, 160, 20 };
    Rectangle abs2 = { 220, 230, 120, 50 };


    Rectangle legs1 = { 240, 310, 110, 20 };
    Rectangle legs2 = { 240, 360, 110, 20 };
    Rectangle legs3 = { 200, 390, 130, 20 };
    Rectangle legs4 = { 200, 430, 130, 20 };
    Rectangle legs5 = { 200, 455, 130, 20 };
    Rectangle legs6 = { 210, 490, 130, 20 };
    Rectangle legs13 = { 210, 520, 130, 20 };
    Rectangle legs7 = { 680, 325, 110, 20 };
    Rectangle legs8 = { 670, 350, 160, 20 };
    Rectangle legs9 = { 670, 380, 80, 20 };
    Rectangle legs10 = { 670, 410, 120, 20 };
    Rectangle legs11 = { 650, 450, 100, 50 };
    Rectangle legs12 = { 330, 560, 130, 20 };

    bool isArms = false;
    bool isChest = false;
    bool isPelvic = false;
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

        if (CheckCollisionPointRec(mousePosition, arms1) || CheckCollisionPointRec(mousePosition, arms3) || CheckCollisionPointRec(mousePosition, arms4) ||
            CheckCollisionPointRec(mousePosition, arms5) || CheckCollisionPointRec(mousePosition, arms6) ||  CheckCollisionPointRec(mousePosition, legs5)||
            CheckCollisionPointRec(mousePosition, legs7) || CheckCollisionPointRec(mousePosition, arms2) || CheckCollisionPointRec(mousePosition, legs4)|| 
            CheckCollisionPointRec(mousePosition, legs8) || CheckCollisionPointRec(mousePosition, legs9) || CheckCollisionPointRec(mousePosition, legs2) 
            )
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isArms = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, abs1) || CheckCollisionPointRec(mousePosition, abs2) || CheckCollisionPointRec(mousePosition, chest))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isChest = true;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, legs1) || CheckCollisionPointRec(mousePosition, legs3))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isPelvic = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, legs1) || 
            CheckCollisionPointRec(mousePosition, legs2) || CheckCollisionPointRec(mousePosition, legs3) ||
             CheckCollisionPointRec(mousePosition, legs4) || CheckCollisionPointRec(mousePosition, legs11) ||
            CheckCollisionPointRec(mousePosition, legs5) || CheckCollisionPointRec(mousePosition, legs6) ||
            CheckCollisionPointRec(mousePosition, legs7) || CheckCollisionPointRec(mousePosition, legs8) ||
            CheckCollisionPointRec(mousePosition, legs9) || CheckCollisionPointRec(mousePosition, legs10) ||
            CheckCollisionPointRec(mousePosition, legs12) || CheckCollisionPointRec(mousePosition, legs13))
            
            
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

        if (isPelvic == true)
        {
            currentBackground = absInfoScreen;
            isPelvic = false;
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
            currentBackground = skeletalInfoScreen;
            goBack = false;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            CloseWindow();
            main();
        }

        EndDrawing();
    }

    CloseWindow();

    UnloadTexture(skeletalInfoScreen);
    UnloadTexture(absInfoScreen);
    UnloadTexture(chestInfoScreen);
    UnloadTexture(armsInfoScreen);
    UnloadTexture(legsInfoScreen);

    return 0;
}
