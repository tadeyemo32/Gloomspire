#pragma once
#include "constants.h"
#include "raylib.h"
#include <unordered_map>

namespace Game
{
  extern std::unordered_map<std::string, Texture2D *> hero_animations;
  void setGameWindowConfig();
  void loadAssets();
  void clearAssets();
  void gameLoop();

}