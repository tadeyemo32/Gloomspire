// game.h
#pragma once
#include "constants.h"
#include "raylib.h"
#include "entity.h"
#include "assetManager.h"
#include "hero.h"

namespace Hero
{
  class Hero;
}

namespace Game
{
  extern AssetManager assetManager;
  extern Hero::Hero *hero;
  void setGameWindowConfig();
  void loadHeroAssets();
  void clearAssets();
  void gameLoop();
}