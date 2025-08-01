#pragma once
#include "hero.h"
#include <unordered_map>

namespace Animation
{
  class AnimationHandler
  {
  private:
    struct AnimationData
    {
      int frameCount;
      int spriteSheetWidth;
      float frameDelay;
    };

    std::unordered_map<Hero::State, AnimationData> animationConfigs;

  public:
    AnimationHandler();
    void HandleAnimation(Hero::Hero &hero);
  };
}