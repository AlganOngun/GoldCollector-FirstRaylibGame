#include "VariableLinkedList.h"

#include <stdlib.h>

#include "Variable.h"

void VariableLinkedList_InsertNode(VariableNode** head, Variable variable) {
  VariableNode* newNode = NULL;

  newNode = malloc(sizeof(*newNode));
  if (newNode == NULL) return;

  newNode->variable = variable;

  newNode->next = *head;
  *head = newNode;
}

void VariableLinkedList_Free(VariableNode* head) {
  VariableNode* tmp;

  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

void VariableLinkedList_DeleteNode(VariableNode** head,
                                   VariableNode** parentNode,
                                   VariableNode** node) {
  if (*parentNode == NULL) {
    *head = (*node)->next;

  } else {
    (*parentNode)->next = (*node)->next;
  }

  *parentNode = *node;
  *node = (*parentNode)->next;

  free(*parentNode);
}
