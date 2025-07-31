#pragma once
#include "entity.h"
#include <iostream>

namespace Hero
{

  class Hero : public Entity::Entity
  {
  public:
    Hero(Texture2D *text, Vector2 p, int x, int y) : Entity(text, p, x, y)
    {
      std::cout << "New Hero\n";
    }
  };

}