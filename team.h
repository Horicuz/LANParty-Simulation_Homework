#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team
{
    char *name;
    int playerCount;
    PLAYER *players;
};

typedef struct Team TEAM;
