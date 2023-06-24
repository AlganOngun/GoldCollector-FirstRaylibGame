#include "World.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Game"

void CreateWindow() { InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE); }

Vector2 ScreenToWorldPoint(Vector2 screenPoint) {
  Vector2 worldPoint = {screenPoint.x - (float)SCREEN_WIDTH / 2,
                        -screenPoint.y + (float)SCREEN_HEIGHT / 2};
  return worldPoint;
}
Vector2 WorldToScreenPoint(Vector2 worldPoint) {
  Vector2 screenPoint = {worldPoint.x + (float)SCREEN_WIDTH / 2,
                         -worldPoint.y + (float)SCREEN_HEIGHT / 2};
  return screenPoint;
}
