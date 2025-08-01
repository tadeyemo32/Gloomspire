#include "animationHandler.h"
#include "hero.h"

namespace Animation
{
  AnimationHandler::AnimationHandler()
  {
    // Initialize animation configurations for each state
    animationConfigs[Hero::State::IDLE] = {8, 768, 0.15f};
    animationConfigs[Hero::State::WALK] = {8, 768, 0.1f};
    animationConfigs[Hero::State::RUN] = {8, 768, 0.05f};
    animationConfigs[Hero::State::JUMP] = {5, 480, 0.15f};
    animationConfigs[Hero::State::HURT] = {4, 384, 0.3f};
    animationConfigs[Hero::State::DEFEND] = {6, 576, 0.25f};
    animationConfigs[Hero::State::ATTACK] = {6, 576, 0.07f};
    animationConfigs[Hero::State::ATTACK2] = {6, 576, 0.07f};
    animationConfigs[Hero::State::ATTACK3] = {6, 576, 0.07f};
    animationConfigs[Hero::State::DEATH] = {12, 1152, 0.2f};
    animationConfigs[Hero::State::Falling] = {5, 480, 0.15f};
  }

  void AnimationHandler::HandleAnimation(Hero::Hero &hero)
  {
    Hero::State currentState = hero.getState();
    AnimationData config = animationConfigs[currentState];

    hero.setFrameDelay(config.frameDelay);

    if (currentState == Hero::State::ATTACK ||
        currentState == Hero::State::ATTACK2 ||
        currentState == Hero::State::ATTACK3 ||
        currentState == Hero::State::HURT ||
        currentState == Hero::State::DEATH)
    {
      if (hero.getCurrentFrame() >= config.frameCount)
      {
        hero.resetFrame();
      }
    }
    else
    {
      hero.setCurrentFrame(hero.getCurrentFrame() % config.frameCount);
    }
  }
}