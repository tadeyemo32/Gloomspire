#include "hero.h"
#include "iostream"
namespace Hero
{

  void Hero::draw()
  {
    const int totalFrames = 8;
    const int spriteSheetWidth = 768;
    const int spriteSheetHeight = 84;

    const int frameWidth = spriteSheetWidth / totalFrames;
    const int frameHeight = spriteSheetHeight;
    Rectangle sourceRec = {float(frameWidth) * currentFrame, 0.0f, (float)frameWidth, (float)frameHeight};

    Rectangle destRec = {pos.x, pos.y, (float)frameWidth, (float)frameHeight};

    Vector2 origin = {0.0f, 0.0f};
    DrawTexturePro(*texture, sourceRec, destRec, origin, 0.0f, WHITE);
  }

  void Hero::update(float deltaTime)
  {
    frameTime += deltaTime;
    if (frameTime >= frameDelay)
    {
      frameTime = 0.0f;
      currentFrame++;

      if (currentFrame >= 8)
        currentFrame = 0;
    }
  }
}