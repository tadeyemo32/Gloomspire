#pragma once
#include "entity.h"
#include <iostream>

namespace Hero
{
  enum State
  {
    IDLE,
    WALK,
    RUN,
    JUMP,
    HURT,
    DEFEND,
    ATTACK,
    ATTACK2,
    ATTACK3,
    DEATH,
    Falling,
  };

  enum Direction
  {
    RIGHT,
    LEFT,
  };

  typedef struct AnimationsTiming
  {
    int currentFrame;
    float frameTime;
    float frameDelay;
  } AnimationsTiming;

  class Hero : public Entity::Entity
  {
  private:
    AnimationsTiming animationsTiming;
    State state;
    Direction direction;
    float speed;
    bool isGrounded;
    float verticalVelocity;
    float jumpForce;
    float gravity;
    float groundLevel;

  public:
    Hero(Texture2D *text, Vector2 p, int x, int y);

    void draw();
    State getState();
    void setState(State newState);

    // Animation control
    void setFrameDelay(float delay);
    float getFrameDelay() const;
    int getCurrentFrame() const;
    void setCurrentFrame(int frame);
    void incrementFrame();
    void resetFrame();

    // Movement
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void runLeft(float deltaTime);
    void runRight(float deltaTime);
    void jump();
    void attack();
    void stop();
    void handleInput();
    void update(float deltaTime);

    // Texture switching
    void switchTexture(const std::string &textureKey);
  };
}