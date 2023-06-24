#ifndef WORLD_H
#define WORLD_H

#include "Variable.h"
#include <raylib.h>

Vector2 ScreenToWorldPoint(Vector2 screenPoint);
Vector2 WorldToScreenPoint(Vector2 worldPoint);

void CreateWindow();

#endif
