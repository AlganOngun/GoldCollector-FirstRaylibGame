#include <raylib.h>

#include "Game.h"
#include "World.h"

int main(void) {
  CreateWindow();
  SetTargetFPS(60);

  Initialize();

  while (!WindowShouldClose()) {
    UpdateLogic();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    Draw();

    EndDrawing();
  }

  Clean();

  CloseWindow();

  return 0;
}
