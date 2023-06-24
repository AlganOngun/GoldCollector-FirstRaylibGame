#include "Game.h"

#include <raylib.h>
#include <stdio.h>

#include "Variable.h"
#include "VariableLinkedList.h"

void HandlePlayerMovement();
void SpawnGold();
void UpdateGolds();
void DrawGolds();
void Score();

#define GOLD_DESTROY_LEVEL -200.0f
#define GOLD_SPAWN_TIMER 2.0f
#define GOLD_FALL_SPEED 0.5f
#define PLAYER_SPEED 2.0f

Variable player = {
    {  0.0f, -150.0f},
    {100.0f,   35.0f},
    RED
};

VariableNode* golds;

float goldSpawnTimer = GOLD_SPAWN_TIMER;

int score = 0;

void Initialize() {
  golds = NULL;
}

void UpdateLogic() {
  HandlePlayerMovement();

  goldSpawnTimer -= GetFrameTime();
  if (goldSpawnTimer <= 0.0f) {
    SpawnGold();

    goldSpawnTimer = GOLD_SPAWN_TIMER;
  }

  UpdateGolds();
}

void HandlePlayerMovement() {
  if (IsKeyDown(KEY_RIGHT)) player.worldPosition.x += PLAYER_SPEED;
  if (IsKeyDown(KEY_LEFT)) player.worldPosition.x -= PLAYER_SPEED;
}

void SpawnGold() {
  Variable gold = {
      {GetRandomValue(-350,  350), 150.0f},
      {              30.0f, 30.0f       },
      YELLOW
  };

  VariableLinkedList_InsertNode(&golds, gold);
}

void UpdateGolds() {
  VariableNode* currentGold = golds;
  VariableNode* parentGold = NULL;

  while (currentGold) {
    currentGold->variable.worldPosition.y -= GOLD_FALL_SPEED;

    if (currentGold->variable.worldPosition.y <= GOLD_DESTROY_LEVEL) {
      VariableLinkedList_DeleteNode(&golds, &parentGold, &currentGold);
    } else if (AreVariablesColliding(player, currentGold->variable)) {
      VariableLinkedList_DeleteNode(&golds, &parentGold, &currentGold);
      Score();
    } else {
      parentGold = currentGold;
      currentGold = currentGold->next;
    }
  }
}

void Score() {
  score++;
}

void Draw() {
  DrawVariable(player);
  DrawGolds();
  DrawText(TextFormat("Score: %i", score), 350, 23, 30, BLUE);
}

void DrawGolds() {
  VariableNode* currentGold = golds;
  while (currentGold) {
    DrawVariable(currentGold->variable);

    currentGold = currentGold->next;
  }
}

void Clean() {
  VariableLinkedList_Free(golds);
}
