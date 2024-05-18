#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkFile(FILE *file)
{
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    FILE *input1, *input2, *output; // c.in, d.in, out.out

    if (argc != 4)
    {
        printf("Usage: %s <input1> <input2> <output>\n", argv[0]);
        exit(1);
    }
    input1 = fopen(argv[1], "r");
    checkFile(input1);
    input2 = fopen(argv[2], "r");
    checkFile(input2);
    output = fopen(argv[3], "w");
    checkFile(output);

    int teamCount;
    fscanf(input2, "%d", &teamCount);

    Node *head = (Node *)malloc(sizeof(Node)); // head of the team list
    if (head == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    head->next = NULL;

    head->val = createTeam(input2);
    for (int i = 0; i < teamCount - 1; i++)
    {
        addAtBeginning(&head, createTeam(input2)); // add the teams in the list
    }

    Node *auxNode = head;

    while (auxNode != NULL)
    {
        fprintf(output, "%s", auxNode->val.name); // print the team name
        auxNode = auxNode->next;
    }

    while (head != NULL) // free the memory
    {
        Node *aux = head;
        head = head->next;
        for (int j = 0; j < aux->val.playerCount; j++)
        {
            free(aux->val.players[j].firstName);
            free(aux->val.players[j].secondName);
        }
        free(aux->val.players);
        free(aux->val.name);
        free(aux);
    }

    fclose(input1); // close the files
    fclose(input2);
    fclose(output);

    return 0;
}