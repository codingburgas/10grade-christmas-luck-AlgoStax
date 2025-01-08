#include "main.h"

int main(void)
{
    const int screenWidth = 1024;
    const int screenHeight = 1024;
    InitWindow(screenWidth, screenHeight, "Algostax");

    const char* dialogTexts[] = {
        "Welcome to the clinic! Let's explore human anatomy.",
        "Did you know? The human skeleton has 206 bones.",
        "The cardiovascular system pumps blood through 60,000 miles of vessels.",
        "Your brain contains over 86 billion neurons!",
        "Muscles make up about 40% of your body weight.",
        "Organs like the heart and lungs keep you alive every second."
    };

    Texture2D defaultBackground = LoadTexture("../assets/backgrounds/clinic-background.png");
    Texture2D skeletonBackground = LoadTexture("../assets/backgrounds/Skeletal-system.png");
    Texture2D cardiovascularBackground = LoadTexture("../assets/backgrounds/Cardiovascular-system.png");
    Texture2D nerveBackground = LoadTexture("../assets/backgrounds/Nerve-system.png");
    Texture2D muscularBackground = LoadTexture("../assets/backgrounds/Muscular-system.png");
    Texture2D organsBackground = LoadTexture("../assets/backgrounds/Organs.png");

    Texture2D currentBackground = defaultBackground;

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

    Rectangle medTable = { 480, 375, 85, 260 };
    Rectangle medTableInterraction = { 475, 370, 95, 270 };
    Rectangle tvTable = { 100, 375, 85, 215 };
    Rectangle computerLeft = { 100, 700, 240, 60 };
    Rectangle bed = { 810, 160, 100, 250 };
    Rectangle topLeftTable = { 100, 180, 235, 150 };
    Rectangle computerArea = { 730, 700, 140, 60 };
    Rectangle interractComputerArea = { 720, 700, 110, 80 };
    Rectangle drawer = { 300, 180, 130, 60 };
    Rectangle drawer2 = { 700, 180, 130, 60 };
    Rectangle drawer3 = { 870, 450, 50, 70 };
    Color transparentColor = { 100, 0, 0, 0 };

    Rectangle characterRect = { characterPosition.x, characterPosition.y, (float)targetWidth, (float)targetHeight };

    bool initialMoveNorth = true;
    float initialMoveDistance = 100.0f;
    float initialMoveSpeed = 50.0f;

    Rectangle screenBounds = { 90, 190, 840, 750 };
    bool interactionScreenActive = false;

    Texture2D systemTextures[5];
    systemTextures[0] = skeletonBackground;
    systemTextures[1] = cardiovascularBackground;
    systemTextures[2] = nerveBackground;
    systemTextures[3] = muscularBackground;
    systemTextures[4] = organsBackground;

    const char* systemLabels[] = {
        "Skeletal system",
        "Cardiovascular system",
        "Nervous system",
        "Muscular system",
        "Organs"
    };

    int currentSystemIndex = 0;

    int currentDialogIndex = 0;
    bool showDialog = true;  
    bool hasMoved = false;   

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();


        characterRect.x = characterPosition.x;
        characterRect.y = characterPosition.y;

        if (!interactionScreenActive)
        {
            UpdateCharacterMovement(characterPosition, velocity, characterRect,
                medTable, bed, computerArea, computerLeft, topLeftTable, tvTable, drawer, drawer2, drawer3, screenBounds, frameTimer,
                currentFrame, isMoving, initialMoveNorth,
                initialMoveDistance, initialMoveSpeed, deltaTime,
                speed, frameSpeed, totalFrames);

                if (initialMoveNorth)
                {
                    hasMoved = false;
                }
                if (isMoving)
                {
                    hasMoved = true;
                }

                if (!hasMoved && showDialog)
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        currentDialogIndex = (currentDialogIndex + 1) % (sizeof(dialogTexts) / sizeof(dialogTexts[0]));
                    }
                }
                else
                {
                    showDialog = false;
                }
            
            if (initialMoveNorth)
            {
                hasMoved = false; 
            }
            if (isMoving)
            {
                hasMoved = true;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!interactionScreenActive)
        {
            DrawTexturePro(
                currentBackground,
                Rectangle{ 0, 0, (float)currentBackground.width, (float)currentBackground.height },
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

                if (showDialog && !hasMoved)
                {
                    DrawRectangle(50, screenHeight - 100, screenWidth - 100, 70, Fade(BLACK, 0.8f));
                    DrawText(dialogTexts[currentDialogIndex], 70, screenHeight - 85, 20, WHITE);
                }
            }

            if (CheckCollisionRecs(characterRect, interractComputerArea))
            {
                DrawText("Press E to interact", characterRect.x, characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E))
                {
                    interactionScreenActive = true;
                }
            }
        }
        else
        {
            DrawTexturePro(
                systemTextures[currentSystemIndex],
                Rectangle{ 0, 0, (float)systemTextures[currentSystemIndex].width, (float)systemTextures[currentSystemIndex].height },
                Rectangle{ 0, 0, (float)screenWidth, (float)screenHeight },
                Vector2{ 0.0f, 0.0f },
                0.0f,
                WHITE);

            DrawText("<", 50, screenHeight / 2 - 20, 40, WHITE);
            DrawText(">", screenWidth - 70, screenHeight / 2 - 20, 40, WHITE);

            DrawText(systemLabels[currentSystemIndex], screenWidth / 2 - MeasureText(systemLabels[currentSystemIndex], 30 / 2), 0, 40, BLACK);

            if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
            {
                currentSystemIndex = (currentSystemIndex - 1 + 5) % 5;
            }

            if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
            {
                currentSystemIndex = (currentSystemIndex + 1) % 5;
            }

            DrawText("Press J to exit systems menu", 380, screenHeight - 170, 20, BLACK);

            DrawText("Press Enter comfirm your choice", 360, screenHeight - 150, 20, BLACK);

            if (IsKeyPressed(KEY_J))
            {
                interactionScreenActive = false;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                currentBackground = systemTextures[currentSystemIndex];
                interactionScreenActive = false;
            }
        }
        if (CheckCollisionRecs(characterRect, medTableInterraction))
        {
            if(currentBackground.id == muscularBackground.id)
            {
                DrawText("Press E to interact", (float)characterRect.x, (float)characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E)) {
                    muscularSystem();
                }
            }
        }

        if (CheckCollisionRecs(characterRect, medTableInterraction))
        {
            if (currentBackground.id == skeletonBackground.id)
            {
                DrawText("Press E to interact", (float)characterRect.x, (float)characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E)) {
                    skeletalSystem();
                }
            }
        }

        if (CheckCollisionRecs(characterRect, medTableInterraction))
        {
            if (currentBackground.id == organsBackground.id)
            {
                DrawText("Press E to interact", (float)characterRect.x, (float)characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E)) {
                    organSystem();
                }
            }
        }

        if (CheckCollisionRecs(characterRect, medTableInterraction))
        {
            if (currentBackground.id == nerveBackground.id)
            {
                DrawText("Press E to interact", (float)characterRect.x, (float)characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E)) {
                    nerveSystem();
                }
            }
        }

        if (CheckCollisionRecs(characterRect, medTableInterraction))
        {
            if (currentBackground.id == cardiovascularBackground.id)
            {
                DrawText("Press E to interact", (float)characterRect.x, (float)characterRect.y - 20, 20, BLACK);
                if (IsKeyDown(KEY_E)) {
                    cardiovascularSystem();
                }
            }
        }

        EndDrawing();
    }
    

    UnloadTexture(defaultBackground);
    UnloadTexture(skeletonBackground);
    UnloadTexture(standingTexture);
    UnloadTexture(cardiovascularBackground);
    UnloadTexture(nerveBackground);
    UnloadTexture(muscularBackground);
    for (int i = 0; i < 2; i++)
    {
        UnloadTexture(backFrames[i]);
        UnloadTexture(leftFrames[i]);
        UnloadTexture(rightFrames[i]);
        UnloadTexture(frontFrames[i]);
    }

    CloseWindow();
}
