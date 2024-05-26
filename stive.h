#include "team.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(Node *top);
void deleteStack(Node **top);
TEAM pop(Node **top);
Node *popMove(Node **top);
void push(Node **top, Node *n);
TEAM top(Node *top);