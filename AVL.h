#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "team.h"

struct AVLNode
{
    int height; // inaltimea
    TEAM val;   // datele efective memorate
    struct AVLNode *left;
    struct AVLNode *right;
};

typedef struct AVLNode AVLNode;

int max(int a, int b);
int nodeHeight(AVLNode *headAVL);
AVLNode *RightRotation(AVLNode *z);
AVLNode *LeftRotation(AVLNode *z);
AVLNode *insertAVL(AVLNode *headAVL, TEAM val);
void printLevel(AVLNode *headAVL, int level, FILE *output);
void freeAVL(AVLNode **headAVL);
void printAVLonLevels(AVLNode *headAVL, FILE *output);
