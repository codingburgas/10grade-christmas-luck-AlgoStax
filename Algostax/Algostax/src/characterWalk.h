#pragma once
#include "pch.h"

void UpdateCharacterMovement(Vector2& characterPosition, Vector2& velocity, Rectangle& characterRect,
    const Rectangle& medTable, const Rectangle& bed, const Rectangle& computerArea, const Rectangle& computerLeft, const Rectangle& topLeftTable, const Rectangle& tvTable, const Rectangle& drawer, const Rectangle& drawer2, const Rectangle& drawer3, const Rectangle screenBounds, float& frameTimer,
    int& currentFrame, bool& isMoving, bool& initialMoveNorth,
    float& initialMoveDistance, float& initialMoveSpeed, float deltaTime,
    float speed, float frameSpeed, int totalFrames);

void DrawCharacterMovement(Texture2D* frames, int currentFrame, Vector2 characterPosition,
    int targetWidth, int targetHeight);
