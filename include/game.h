#pragma once
#include "constants.h"
#include "raylib.h"
#include "entity.h"
#include "assetManager.h"
#include "hero.h"
#include "animationHandler.h"

namespace Game
{
  extern AssetManager assetManager;
  extern Animation::AnimationHandler animationHandler;
  extern Hero::Hero *hero;

  void setGameWindowConfig();
  void loadHeroAssets();
  void clearAssets();
  void gameLoop();
}