#include "AVL.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int nodeHeight(AVLNode *headAVL) // inaltimea unui nod
{
    if (headAVL == NULL)
        return -1;
    else
        return headAVL->height;
}

AVLNode *RightRotation(AVLNode *z) // rotatie dreapta
{
    AVLNode *y = z->left;
    AVLNode *T3 = y->right;
    // Rotate
    y->right = z;
    z->left = T3;
    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y; // new root
}

AVLNode *LeftRotation(AVLNode *z) // rotatie stanga
{
    AVLNode *y = z->right;
    AVLNode *T2 = y->left;
    // Rotate
    y->left = z;
    z->right = T2;
    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y; // new root
}

AVLNode *insertAVL(AVLNode *headAVL, TEAM val) // inserare in AVL
{
    if (headAVL == NULL)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }
    if (val.teamPoints < headAVL->val.teamPoints)
        headAVL->left = insertAVL(headAVL->left, val);
    else if (val.teamPoints > headAVL->val.teamPoints)
        headAVL->right = insertAVL(headAVL->right, val);
    else if (strcmp(val.name, headAVL->val.name) < 0)
        headAVL->left = insertAVL(headAVL->left, val);
    else if (strcmp(val.name, headAVL->val.name) > 0)
        headAVL->right = insertAVL(headAVL->right, val);

    headAVL->height = 1 + max(nodeHeight(headAVL->left), nodeHeight(headAVL->right));
    int balance = nodeHeight(headAVL->left) - nodeHeight(headAVL->right);
    // Left Left
    if (balance > 1 && (val.teamPoints < headAVL->left->val.teamPoints || (val.teamPoints == headAVL->left->val.teamPoints && strcmp(val.name, headAVL->left->val.name) < 0)))
        return RightRotation(headAVL);
    // Right Right
    if (balance < -1 && (val.teamPoints > headAVL->right->val.teamPoints || (val.teamPoints == headAVL->right->val.teamPoints && strcmp(val.name, headAVL->right->val.name) > 0)))
        return LeftRotation(headAVL);
    // Left Right
    if (balance > 1 && (val.teamPoints > headAVL->left->val.teamPoints || (val.teamPoints == headAVL->left->val.teamPoints && strcmp(val.name, headAVL->left->val.name) > 0)))
    {
        headAVL->left = LeftRotation(headAVL->left);
        return RightRotation(headAVL);
    }
    // Right Left
    if (balance < -1 && (val.teamPoints < headAVL->right->val.teamPoints || (val.teamPoints == headAVL->right->val.teamPoints && strcmp(val.name, headAVL->right->val.name) < 0)))
    {
        headAVL->right = RightRotation(headAVL->right);
        return LeftRotation(headAVL);
    }
    if (balance < -1 && val.teamPoints < headAVL->right->val.teamPoints)
    {
        headAVL->right = RightRotation(headAVL->right);
        return LeftRotation(headAVL);
    }
    return headAVL;
}

void printLevel(AVLNode *headAVL, int level, FILE *output) // afisare pe nivel
{
    if (headAVL == NULL)
        return;
    if (level == 0)
    {
        fprintf(output, "%s\n", headAVL->val.name);
    }
    else if (level > 0)
    {
        printLevel(headAVL->right, level - 1, output);
        printLevel(headAVL->left, level - 1, output);
    }
}

void freeAVL(AVLNode **headAVL) // eliberare memorie
{
    if (*headAVL == NULL)
        return;
    freeAVL(&(*headAVL)->left);
    freeAVL(&(*headAVL)->right);
    free(*headAVL);
    *headAVL = NULL;
}

void printAVLonLevels(AVLNode *headAVL, FILE *output) // afisare AVL pe nivele
{
    int h = nodeHeight(headAVL);
    for (int i = 1; i <= h + 1; i++)
    {
        printLevel(headAVL, i, output);
        fprintf(output, "\n");
    }
}