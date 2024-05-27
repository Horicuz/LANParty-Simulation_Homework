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
    else if (strcmp(key.name, node->team.name) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key.name, node->team.name) > 0)
        node->right = insert(node->right, key);
    return node;
}

void printRevInorder(TreeNode *root, FILE *output)
{
    if (root != NULL)
    {
        printRevInorder(root->right, output);
        fprintf(output, "%s", root->team.name);
        for (int i = 1; i <= 34 - strlen(root->team.name); i++)
            fprintf(output, " ");
        fprintf(output, "-  %.2f\n", root->team.teamPoints);
        printRevInorder(root->left, output);
    }
}

void printInorder(TreeNode *root, FILE *output)
{
    if (root != NULL)
    {
        printInorder(root->left, output);
        fprintf(output, "%s", root->team.name);
        for (int i = 1; i <= 34 - strlen(root->team.name); i++)
            fprintf(output, " ");
        fprintf(output, "-  %.2f\n", root->team.teamPoints);
        printInorder(root->right, output);
    }
}

void freeBST(TreeNode **root)
{
    if (*root == NULL)
        return;
    freeBST(&(*root)->left);
    freeBST(&(*root)->right);
    free(*root);
    *root = NULL;
}