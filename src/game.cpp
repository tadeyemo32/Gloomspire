#include "game.h"
#include "raylib.h"
#include "constants.h"
#include "hero.h"

namespace Game
{
  AssetManager assetManager;
  Animation::AnimationHandler animationHandler;
  Hero::Hero *hero = nullptr;

  void loadHeroAssets()
  {
    assetManager.LoadTexture("IDLE", "assets/hero/IDLE.png");
    assetManager.LoadTexture("WALK", "assets/hero/WALK.png");
    assetManager.LoadTexture("RUN", "assets/hero/RUN.png");
    assetManager.LoadTexture("JUMP", "assets/hero/JUMP.png");
    assetManager.LoadTexture("ATTACK", "assets/hero/ATTACK 1.png");
    assetManager.LoadTexture("HURT", "assets/hero/HURT.png");
    assetManager.LoadTexture("DEFEND", "assets/hero/DEFEND.png");
    assetManager.LoadTexture("DEATH", "assets/hero/DEATH.png");
    assetManager.LoadTexture("Falling", "assets/hero/JUMP.png"); // Using jump sprites for falling

    hero = new Hero::Hero(assetManager.GetTexture("IDLE"), {720 / 2, 720 / 2}, 32, 32);
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

  void setGameWindowConfig()
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

      hero->update(deltaTime);
      animationHandler.HandleAnimation(*hero);

      BeginDrawing();
      ClearBackground(SKYBLUE);

      // Draw ground
      DrawRectangle(0, GetScreenHeight() - 50, GetScreenWidth(), 50, GREEN);

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