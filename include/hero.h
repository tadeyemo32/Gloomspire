#pragma once
#include "entity.h"
#include <iostream>

namespace Hero
{

  class Hero : public Entity::Entity
  {
  private:
    int currentFrame = 0;
    float frameTime = 0.0f;
    const float frameDelay = 0.1f;
    std::string state = "IDLE";

  public:
    Hero(Texture2D *text, Vector2 p, int x, int y) : Entity(text, p, x, y)
    {
      std::cout << "New Hero\n";
    }

    void draw();

    void update(float deltaTime);
  };

}