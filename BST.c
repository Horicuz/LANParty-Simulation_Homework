#include "BST.h"

TreeNode *newNode(TEAM team)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->team = team;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert(TreeNode *node, TEAM key)
{
    if (node == NULL)
        return newNode(key);
    if (key.teamPoints < node->team.teamPoints)
        node->left = insert(node->left, key);
    else if (key.teamPoints > node->team.teamPoints)
        node->right = insert(node->right, key);
    return node;
}