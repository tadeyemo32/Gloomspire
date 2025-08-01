#include "hero.h"
#include "raylib.h"
#include <iostream>
#include "game.h"

namespace Hero
{
  Hero::Hero(Texture2D *text, Vector2 p, int x, int y) : Entity(text, p, x, y)
  {
    state = IDLE;
    direction = RIGHT;
    animationsTiming.currentFrame = 0;
    animationsTiming.frameDelay = 0.1f;
    animationsTiming.frameTime = 0.1f;
    speed = 300.0f;
    isGrounded = true;
    verticalVelocity = 0.0f;
    jumpForce = 500.0f;
    gravity = 1500.0f;
    groundLevel = GetScreenHeight() - 100.0f;
  }

  void Hero::switchTexture(const std::string &textureKey)
  {
    Texture2D *newTexture = Game::assetManager.GetTexture(textureKey);
    if (newTexture)
    {
      texture = newTexture;
    }
  }

  State Hero::getState() { return state; }

  void Hero::draw()
  {
    if (!texture)
      return;

    int frameCount = 8;
    int spriteWidth = 768;

    switch (state)
    {
    case IDLE:
      frameCount = 8;
      spriteWidth = 768;
      break;
    case WALK:
      frameCount = 8;
      spriteWidth = 768;
      break;
    case RUN:
      frameCount = 8;
      spriteWidth = 768;
      break;
    case JUMP:
      frameCount = 5;
      spriteWidth = 480;
      break;
    case HURT:
      frameCount = 4;
      spriteWidth = 384;
      break;
    case DEFEND:
      frameCount = 6;
      spriteWidth = 576;
      break;
    case ATTACK:
    case ATTACK2:
    case ATTACK3:
      frameCount = 6;
      spriteWidth = 576;
      break;
    case DEATH:
      frameCount = 12;
      spriteWidth = 1152;
      break;
    case Falling:
      frameCount = 5;
      spriteWidth = 480;
      break;
    }

    const int frameWidth = spriteWidth / frameCount;
    const int frameHeight = 84;
    float sourceWidth = (direction == RIGHT) ? frameWidth : -frameWidth;

    Rectangle sourceRec = {
        (direction == RIGHT) ? (float)(frameWidth * animationsTiming.currentFrame)
                             : (float)(frameWidth * (animationsTiming.currentFrame + 1)),
        0.0f,
        sourceWidth,
        (float)frameHeight};
    Rectangle destRec = {pos.x, pos.y, (float)frameWidth, (float)frameHeight};

    DrawTexturePro(*texture, sourceRec, destRec, Vector2{0}, 0.0f, WHITE);
  }

  void Hero::setState(State newState)
  {
    if (state != newState)
    {
      state = newState;
      resetFrame();

      // Switch texture based on state
      switch (state)
      {
      case IDLE:
        switchTexture("IDLE");
        break;
      case WALK:
        switchTexture("WALK");
        break;
      case RUN:
        switchTexture("RUN");
        break;
      case JUMP:
        switchTexture("JUMP");
        break;
      case HURT:
        switchTexture("HURT");
        break;
      case DEFEND:
        switchTexture("DEFEND");
        break;
      case ATTACK:
      case ATTACK2:
      case ATTACK3:
        switchTexture("ATTACK");
        break;
      case DEATH:
        switchTexture("DEATH");
        break;
      case Falling:
        switchTexture("JUMP");
        break; // Use jump sprites for falling
      }
    }
  }

  // Animation control
  void Hero::setFrameDelay(float delay) { animationsTiming.frameDelay = delay; }
  float Hero::getFrameDelay() const { return animationsTiming.frameDelay; }
  int Hero::getCurrentFrame() const { return animationsTiming.currentFrame; }
  void Hero::setCurrentFrame(int frame) { animationsTiming.currentFrame = frame; }
  void Hero::incrementFrame() { animationsTiming.currentFrame++; }
  void Hero::resetFrame() { animationsTiming.currentFrame = 0; }

  // Movement
  void Hero::moveLeft(float deltaTime)
  {
    direction = LEFT;
    pos.x -= speed * deltaTime;
    setState(WALK);
  }

  void Hero::moveRight(float deltaTime)
  {
    direction = RIGHT;
    pos.x += speed * deltaTime;
    setState(WALK);
  }

  void Hero::runLeft(float deltaTime)
  {
    direction = LEFT;
    pos.x -= speed * 1.5f * deltaTime;
    setState(RUN);
  }

  void Hero::runRight(float deltaTime)
  {
    direction = RIGHT;
    pos.x += speed * 1.5f * deltaTime;
    setState(RUN);
  }

  void Hero::jump()
  {
    if (isGrounded)
    {
      setState(JUMP);
      isGrounded = false;
      verticalVelocity = -jumpForce;
    }
  }

  void Hero::attack()
  {
    if (state != ATTACK && state != ATTACK2 && state != ATTACK3)
    {
      setState(ATTACK);
    }
  }

  void Hero::stop()
  {
    if (isGrounded)
    {
      setState(IDLE);
    }
  }

  void Hero::handleInput()
  {
    bool moving = false;

    if (IsKeyDown(KEY_LEFT))
    {
      if (IsKeyDown(KEY_LEFT_SHIFT))
        runLeft(GetFrameTime());
      else
        moveLeft(GetFrameTime());
      moving = true;
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
      if (IsKeyDown(KEY_LEFT_SHIFT))
        runRight(GetFrameTime());
      else
        moveRight(GetFrameTime());
      moving = true;
    }

    if (IsKeyPressed(KEY_SPACE))
      jump();
    if (IsKeyPressed(KEY_Z))
      attack();

    if (!moving && isGrounded)
      stop();
  }

  void Hero::update(float deltaTime)
  {
    handleInput();

    // Apply gravity
    if (!isGrounded)
    {
      verticalVelocity += gravity * deltaTime;
      pos.y += verticalVelocity * deltaTime;
    }

    // Ground check
    if (pos.y >= groundLevel)
    {
      pos.y = groundLevel;
      isGrounded = true;
      verticalVelocity = 0;
      if (state == JUMP || state == Falling)
        setState(IDLE);
    }
    else if (!isGrounded && verticalVelocity > 0)
    {
      setState(Falling);
    }

    // Animation update
    animationsTiming.frameTime += deltaTime;
    if (animationsTiming.frameTime >= animationsTiming.frameDelay)
    {
      animationsTiming.frameTime = 0.0f;
      incrementFrame();

      // Handle animation looping
      int maxFrames = 8; // Default
      switch (state)
      {
      case JUMP:
        maxFrames = 5;
        break;
      case HURT:
        maxFrames = 4;
        break;
      case DEFEND:
      case ATTACK:
      case ATTACK2:
      case ATTACK3:
        maxFrames = 6;
        break;
      case DEATH:
        maxFrames = 12;
        break;
      case Falling:
        maxFrames = 5;
        break;
      }

      if (animationsTiming.currentFrame >= maxFrames)
      {
        if (state == ATTACK)
          setState(ATTACK2);
        else if (state == ATTACK2)
          setState(ATTACK3);
        else if (state == ATTACK3)
          setState(IDLE);
        else
          resetFrame();
      }
    }
  }
}