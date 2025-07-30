#pragma once
#include "raylib.h"
#include <iostream>

namespace Entity
{
  class Entity
  {
  private:
    int health = 100;
    Vector2 pos;
    Texture2D *texture;

  public:
    Entity(Texture2D *text, Vector2 p, int x, int y)
    {
      std::cout << "Entity created" << " X:" << p.x << " Y:" << p.y << std::endl;
      texture = text;
      pos = p;
    }
  };

}