#include "game.h"
#include "raylib.h"
#include "constants.h"
#include "hero.h"

namespace Game
{
  void loadAssets()
  {
  }
  void clearAssets()
  {
  }
  std::unordered_map<std::string, Texture2D *> hero_animations;
  void setGameWindowConfig()
  {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
    InitWindow(Constants::width, Constants::height, Constants::windowName.c_str());
    SetWindowPosition(GetMonitorWidth(0) / 2 - Constants::width / 2, GetMonitorHeight(0) / 2 - Constants::height / 2);
    SetTargetFPS(Constants::targetFPS);
    loadAssets();
  }

  void gameLoop()
  {

    while (!WindowShouldClose())
    {
      float deltaTime = GetFrameTime();

      BeginDrawing();
      ClearBackground(SKYBLUE);
      // update code here
      EndDrawing();
    }
    clearAssets();
    CloseWindow();
  }
}