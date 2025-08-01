#include "raylib.h"
#include "constants.h"
#include "game.h"
#include "hero.h"

int main()
{
  Game::setGameWindowConfig();
  Game::gameLoop();
  return 0;

}
