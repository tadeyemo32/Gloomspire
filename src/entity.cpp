#include "entity.h"
#include "raylib.h"
#include <iostream>

namespace Entity
{
  void Entity::draw()
  {
    if (texture)
    {
      const int totalFrames = 8;
      const int spriteSheetWidth = 768;
      const int spriteSheetHeight = 84;

      const int frameWidth = spriteSheetWidth / totalFrames;
      const int frameHeight = spriteSheetHeight;
      Rectangle sourceRec = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight};

      Rectangle destRec = {pos.x, pos.y, (float)frameWidth, (float)frameHeight};

      Vector2 origin = {0.0f, 0.0f};
      DrawTexturePro(*texture, sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else
    {
      std::cout << "Unable to create Entity Object" << std::endl;
      DrawRectangleV(pos, {32, 32}, GRAY);
    }
  }
}