#include "BST.h"

TreeNode *newNode(TEAM team) // creare nod
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->team = team;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert(TreeNode *node, TEAM key) // inserare in BST
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

void insertListInBST(Node *head, TreeNode **bst) // inserare lista in BST
{
    while (head != NULL)
    {
        *bst = insert(*bst, head->val);
        Node *aux = head;
        head = head->next;
        free(aux);
    }
}

void printRevInorder(TreeNode *root, FILE *output) // afisare in ordine inversa
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

void printInorder(TreeNode *root, FILE *output) // afisare in ordine
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

void freeBST(TreeNode **root) // eliberare memorie BST
{
    if (*root == NULL)
        return;
    freeBST(&(*root)->left);
    freeBST(&(*root)->right);
    free(*root);
    *root = NULL;
}

void AddAVLRevInorder(TreeNode *root, AVLNode **headAVL) // adaugare in AVL in ordine inversa
{
    if (root != NULL)
    {
        AddAVLRevInorder(root->right, headAVL);
        *headAVL = insertAVL(*headAVL, root->team);
        AddAVLRevInorder(root->left, headAVL);
    }
}