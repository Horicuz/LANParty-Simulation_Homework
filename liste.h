#include "team.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    TEAM val;
    struct Node *next;
};

typedef struct Node Node;

void addAtBeginning(Node **head, TEAM v);
void addAtEnd(Node **head, TEAM v);
void deleteNode(Node **head, TEAM v);

TEAM createTeam(FILE *file);

void deleteMin(Node **head);
void printList(Node *head, FILE *output);
void freeMem(Node **head);
