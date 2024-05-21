#include "match.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MatchNode
{
    struct Match val;
    struct MatchNode *next;
};

typedef struct MatchNode MatchNode;

struct Queue
{
    MatchNode *front;
    MatchNode *rear;
};

typedef struct Queue Queue;

Queue *createQueue();
int isEmpty(Queue *q);
MATCH deQueue(Queue *q);
void enQueue(Queue *q, MATCH v);
