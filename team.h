#include "player.h"
#pragma once

struct Team
{
    char *name;
    int playerCount;
    PLAYER *players;
    float teamPoints;
};

typedef struct Team TEAM;

struct Node
{
    TEAM val;
    struct Node *next;
};

typedef struct Node Node;
