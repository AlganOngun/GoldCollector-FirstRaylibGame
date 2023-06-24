#include "Variable.h"

#include <math.h>

#include "World.h"

void DrawVariable(Variable variable) {
  DrawRectangleV(WorldToScreenPoint(variable.worldPosition), variable.size, variable.color);
}

bool AreVariablesColliding(Variable a, Variable b) {
  return (abs(((int)a.worldPosition.x + (int)a.size.x / 2)
              - ((int)b.worldPosition.x + (int)b.size.x / 2))
              * 2
          < ((int)a.size.x + (int)b.size.x))
         && (abs(((int)a.worldPosition.y + (int)a.size.y / 2)
                 - ((int)b.worldPosition.y + (int)b.size.y / 2))
                 * 2
             < ((int)a.size.y + (int)b.size.y));
}
