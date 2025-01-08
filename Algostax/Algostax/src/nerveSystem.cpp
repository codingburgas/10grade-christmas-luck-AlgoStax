#include "nerveSystem.h"

int nerveSystem(void)
{
    const int screenWidth = 1100;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Nerve System");

    Texture2D nerveInfoScreen = LoadTexture("../assets/backgrounds/nerveSystemInfo.png");
    Texture2D brainInfoScreen = LoadTexture("../assets/backgrounds/BrainParts.png");
    Texture2D neuronInfoScreen = LoadTexture("../assets/backgrounds/NeuronParts.png");
    Texture2D EyeInfoScreen = LoadTexture("../assets/backgrounds/EyeParts.png");
    Texture2D SpinalCordInfoScreen = LoadTexture("../assets/backgrounds/SpinalCord.png");

    Texture2D currentBackground = nerveInfoScreen;

    const char* facts[] = {
        "The brain has 86 billion neurons.",
        "Nerve impulses can travel up to 250 miles per hour.",
        "The spinal cord, 18 inches long, links brain and body.",
        "The peripheral nerves connect brain, spinal cord, and organs.",
        "Neurons use electrical signals and chemicals to communicate.",
        "The brain adapts through neuroplasticity."
    };

    Rectangle neuron = { 650, 120, 120, 20 };
    Rectangle eye = { 520, 90, 70, 20 };
    Rectangle spinal = { 345, 130, 70, 20 };
    Rectangle brain = { 345, 100, 70, 20 };

    int currentDialogIndex = 0;
    bool showDialog = true;

    bool isNeuron = false;
    bool isBrain = false;
    bool isSpinal = false;
    bool isEye = false;
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

        if (goBack == true) {
            DrawText("< Press 'SPACE' to go back", 20, 10, 10, GRAY);
        }

        if (goBack == false)
        {
            DrawText("< Press 'ENTER' to go back", 20, 10, 10, GRAY);
        }

        Vector2 mousePosition = GetMousePosition();

        if (showDialog && currentDialogIndex < (sizeof(facts) / sizeof(facts[0])))
        {
            DrawRectangle(130, screenHeight - 100, screenWidth - 250, 70, Fade(BLACK, 0.8f));
            DrawText(facts[currentDialogIndex], 140, screenHeight - 85, 20, WHITE);
            DrawText("Press 'D' to continue", 850, screenHeight - 55, 10, GRAY);
        }

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
            goBack = true;
        }

        if (isBrain == true)
        {
            currentBackground = brainInfoScreen;
            isBrain = false;
            goBack = true;
        }

        if (isEye == true)
        {
            currentBackground = EyeInfoScreen;
            isEye = false;
            goBack = true;
        }

        if (isSpinal == true)
        {
            currentBackground = SpinalCordInfoScreen;
            isSpinal = false;
            goBack = true;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            currentBackground = nerveInfoScreen;
            goBack = false;
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
