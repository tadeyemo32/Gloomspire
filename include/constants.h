#pragma once
#include "raylib.h"
#include <string>

namespace Constants
{
  const int screenHeight = GetScreenHeight(); // screen Height
  const int screenWidth = GetScreenWidth();   // screen Widht
  constexpr int width = 1280;                 // set window width
  constexpr int height = 720;                 // set window height
  const int targetFPS = 60;
  const std::string windowName = "Gloomspire-Z"; // set window name

}
