#pragma once
#include "pch.h"

void UpdateCharacterMovement(Vector2& characterPosition, Vector2& velocity, Rectangle& characterRect,
    const Rectangle& medTable, const Rectangle& bed,  const Rectangle& computerAre,const Rectangle screenBounds, float& frameTimer,
    int& currentFrame, bool& isMoving, bool& initialMoveNorth,
    float& initialMoveDistance, float& initialMoveSpeed, float deltaTime,
    float speed, float frameSpeed, int totalFrames);

void DrawCharacterMovement(Texture2D* frames, int currentFrame, Vector2 characterPosition,
    int targetWidth, int targetHeight);
