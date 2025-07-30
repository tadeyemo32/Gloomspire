// game.h
#pragma once
#include "constants.h"
#include "raylib.h"
#include "entity.h"
#include "assetManager.h"

namespace Game
{
  extern AssetManager assetManager;
  extern Entity::Entity *hero;
  void setGameWindowConfig();
  void loadHeroAssets();
  void clearAssets();
  void gameLoop();
}