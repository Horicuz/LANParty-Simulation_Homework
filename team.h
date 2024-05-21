#include "player.h"
#pragma once

struct Team
{
    char *name;
    int playerCount;
    PLAYER *players;
    float teamPoints;
};

struct Node
{
    TEAM val;
    struct Node *next;
};

typedef struct Node Node;

typedef struct Team TEAM;
