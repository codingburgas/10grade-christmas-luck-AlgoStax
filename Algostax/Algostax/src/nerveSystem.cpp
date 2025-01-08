#include "nerveSystem.h"

int nerveSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Nerve System");

    Texture2D nerveInfoScreen = LoadTexture("../assets/backgrounds/NerveSystemInfo.png");
    Texture2D brainInfoScreen = LoadTexture("../assets/backgrounds/BrainParts.png");
    Texture2D neuronInfoScreen = LoadTexture("../assets/backgrounds/NeuronParts.png");
    Texture2D EyeInfoScreen = LoadTexture("../assets/backgrounds/EyeParts.png");
    Texture2D SpinalCordInfoScreen = LoadTexture("../assets/backgrounds/SpinalCord.png");

    Texture2D currentBackground = nerveInfoScreen;

    Rectangle neuron = { 650, 120, 120, 20 };
    Rectangle eye = { 520, 90, 70, 20 };
    Rectangle spinal = { 345, 130, 70, 20 };
    Rectangle brain = { 345, 100, 70, 20 };

  

    bool isNeuron = false;
    bool isBrain = false;
    bool isSpinal = false;
    bool isEye = false;

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

        if (CheckCollisionPointRec(mousePosition, neuron))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isNeuron = true;
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
        else if (CheckCollisionPointRec(mousePosition,eye))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isEye = true;
            }
        }

        else if (CheckCollisionPointRec(mousePosition, spinal))


        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                isSpinal = true;
            }
        }

        else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if (isNeuron == true)
        {
            currentBackground = neuronInfoScreen;
            isNeuron = false;
        }

        if (isBrain == true)
        {
            currentBackground = brainInfoScreen;
            isBrain = false;
        }

        if (isEye == true)
        {
            currentBackground = EyeInfoScreen;
            isEye = false;
        }

        if (isSpinal == true)
        {
            currentBackground = SpinalCordInfoScreen;
            isSpinal = false;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = nerveInfoScreen;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            CloseWindow();
            main();
        }

        EndDrawing();
    }

    UnloadTexture(brainInfoScreen);
    UnloadTexture(neuronInfoScreen);
    UnloadTexture(EyeInfoScreen);
    UnloadTexture(nerveInfoScreen);

    CloseWindow();

    return 0;
}
