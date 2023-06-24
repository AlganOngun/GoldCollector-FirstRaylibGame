#ifndef VARIABLE_H
#define VARIABLE_H

#include <raylib.h>

struct Variable {
  Vector2 worldPosition;
  Vector2 size;
  Color color;
} typedef Variable;

void DrawVariable(Variable variable);

bool AreVariablesColliding(Variable a, Variable b);

#endif
