#ifndef VARIABLE_LINKED_LIST_H
#define VARIABLE_LINKED_LIST_H

#include "Variable.h"

typedef struct VariableNode {
  struct VariableNode* next;

  Variable variable;
} VariableNode;

void VariableLinkedList_InsertNode(VariableNode** head, Variable variable);
void VariableLinkedList_Free(VariableNode* head);
void VariableLinkedList_DeleteNode(VariableNode** head,
                                   VariableNode** parentNode,
                                   VariableNode** node);

#endif
