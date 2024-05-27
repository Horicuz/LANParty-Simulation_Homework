#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"

struct TreeNode
{
    TEAM team;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *newNode(TEAM team);
TreeNode *insert(TreeNode *node, TEAM key);
void printRevInorder(TreeNode *root, FILE *output);
void printInorder(TreeNode *root, FILE *output);
void freeBST(TreeNode **root);