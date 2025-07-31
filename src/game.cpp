#include "game.h"
#include "raylib.h"
#include "constants.h"
#include "hero.h"

namespace Game
{

  AssetManager assetManager;
  Hero::Hero *hero = nullptr;

  void loadHeroAssets()
  {
    assetManager.LoadTexture("ATTACK_1", "assets/hero/ATTACK 1.png");
    assetManager.LoadTexture("WALK", "assets/hero/WALK.png");
    assetManager.LoadTexture("RUN", "assets/hero/RUN.png");
    assetManager.LoadTexture("JUMP", "assets/hero/JUMP.png");
    assetManager.LoadTexture("IDLE", "assets/hero/IDLE.png");

    hero = new Hero::Hero(assetManager.GetTexture("IDLE"), {720 / 2, 720 / 2}, 32, 32); // initial hero positon
  }

  void clearAssets()
  {
    if (hero != nullptr)
    {
      delete hero;
      hero = nullptr;
    }
    assetManager.UnloadAllTextures();
  }
  void setGameWindowConfig() // window config
  {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
    InitWindow(Constants::width, Constants::height, Constants::windowName.c_str());
    SetWindowPosition(GetMonitorWidth(0) / 2 - Constants::width / 2, GetMonitorHeight(0) / 2 - Constants::height / 2);
    SetTargetFPS(Constants::targetFPS);
    loadHeroAssets();
  }

  void gameLoop()
  {
    while (!WindowShouldClose())
    {
      float deltaTime = GetFrameTime();

      BeginDrawing();
      ClearBackground(SKYBLUE);

      // Draw the hero
      if (hero != nullptr)
      {
        hero->draw();
      }

      EndDrawing();
    }
    clearAssets();
    CloseWindow();
  }
}