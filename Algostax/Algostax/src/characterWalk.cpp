#include "pch.h"

void UpdateCharacterMovement(Vector2& characterPosition, Vector2& velocity, Rectangle& characterRect,
    const Rectangle& medTable, const Rectangle& bed, const Rectangle& computerArea, const Rectangle screenBounds, float& frameTimer,
    int& currentFrame, bool& isMoving, bool& initialMoveNorth,
    float& initialMoveDistance, float& initialMoveSpeed, float deltaTime,
    float speed, float frameSpeed, int totalFrames)
{
    velocity = { 0.0f, 0.0f };

    if (initialMoveNorth) {
        float moveAmount = initialMoveSpeed * deltaTime;
        characterPosition.y -= moveAmount;
        initialMoveDistance -= moveAmount;

        if (initialMoveDistance <= 0) {
            initialMoveNorth = false;
        }
    }
    else {
        if (IsKeyDown(KEY_W)) velocity.y -= speed;
        if (IsKeyDown(KEY_S)) velocity.y += speed;
        if (IsKeyDown(KEY_A)) velocity.x -= speed;
        if (IsKeyDown(KEY_D)) velocity.x += speed;

        if (velocity.x != 0.0f && velocity.y != 0.0f) {
            velocity.x /= sqrt(2.0f);
            velocity.y /= sqrt(2.0f);
        }

        Vector2 nextPosition = {
            characterPosition.x + velocity.x * deltaTime,
            characterPosition.y + velocity.y * deltaTime
        };

        Rectangle nextRect = { nextPosition.x, nextPosition.y, characterRect.width, characterRect.height };

        // Prevent movement through obstacles
        if (!CheckCollisionRecs(nextRect, medTable) && !CheckCollisionRecs(nextRect, bed) &&
            !CheckCollisionRecs(nextRect, computerArea)) {
            if (nextRect.x >= screenBounds.x &&
                nextRect.y >= screenBounds.y &&
                nextRect.x + nextRect.width <= screenBounds.x + screenBounds.width &&
                nextRect.y + nextRect.height <= screenBounds.y + screenBounds.height) {
                characterPosition = nextPosition;
            }
        }

        isMoving = (velocity.x != 0.0f || velocity.y != 0.0f);
    }

    if (isMoving || initialMoveNorth) {
        frameTimer += deltaTime;
        if (frameTimer >= frameSpeed) {
            frameTimer = 0.0f;
            currentFrame++;
            if (currentFrame >= totalFrames) currentFrame = 0;
        }
    }

    characterRect.x = characterPosition.x;
    characterRect.y = characterPosition.y;
}




void DrawCharacterMovement(Texture2D* frames, int currentFrame, Vector2 characterPosition,
    int targetWidth, int targetHeight)
{
    DrawTexturePro(frames[currentFrame],
        Rectangle{ 0, 0, (float)frames[0].width, (float)frames[0].height },
        Rectangle{ characterPosition.x, characterPosition.y, (float)targetWidth, (float)targetHeight },
        Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);
}