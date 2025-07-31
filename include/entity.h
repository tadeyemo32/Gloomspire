#pragma once
#include "raylib.h"
#include <iostream>

namespace Entity
{
  class Entity
  {
  protected:
    int health = 100;
    Vector2 pos;
    Texture2D *texture;
    Vector2 source;

  public:
    Entity(Texture2D *text, Vector2 p, int x, int y)
    {
      source.x = x;
      source.y = y;
      std::cout << "Entity created Succefully Position - " << " X:" << p.x << " Y:" << p.y << std::endl;
      texture = text;
      pos = p;
    }
    virtual ~Entity() = default;
    virtual void draw();
  };

}