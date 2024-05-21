#include "cozi.h"
#include "liste.h"
#include "stive.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int task = 0;
    for (int i = 0; i < 5; i++) // check what task the checker will run
    {
        int k;
        fscanf(input1, "%d", &k);
        if (k == 0)
            break;
        else
            task++;
    }

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
        TEAM t = createTeam(input2);
        addAtBeginning(&head, t); // add the teams in the list
    }

    if (task == 1) // task 1
    {
        printList(head, output);
        freeMem(&head);
        closeFiles(input1, input2, output);
        return 0;
    }

    int remainingTeams = 1;
    while (remainingTeams <= teamCount)
    {
        remainingTeams *= 2; // determine the number of remaining teams
    }
    remainingTeams /= 2;

    for (int i = 0; i < teamCount - remainingTeams; i++)
    {
        deleteMin(&head); // delete the team with the lowest average points
    }

    printf("Remaining teams: %d\n", remainingTeams);

    if (task == 2) // task 2
    {
        printList(head, output);
        freeMem(&head);
        closeFiles(input1, input2, output);
        return 0;
    }

    Node *aux = head;
    Queue *q = createQueue(); // the queue of matches
    while (aux != NULL)
    {
        MATCH m;
        m.team1 = aux->val;
        m.team2 = aux->next->val;
        enQueue(q, m);
        aux = aux->next->next;
    }

    Node *LoserStack = NULL;
    Node *WinnerStack = NULL;

    while (!isEmpty(q))
    {
        MATCH m = deQueue(q);
        if (m.team1.teamPoints >= m.team2.teamPoints)
        {
            m.team1.teamPoints++;
            push(&WinnerStack, m.team1);
            push(&LoserStack, m.team2);
        }
        else
        {
            m.team2.teamPoints++;
            push(&WinnerStack, m.team2);
            push(&LoserStack, m.team1);
        }
    }

    while (!isEmpty(&LoserStack))
    {
        pop(&LoserStack);
    }

    while (!isEmpty(&WinnerStack))
    {
        TEAM temp = pop(&WinnerStack);
    }
    // while (remainingTeams > 1)
    // {
    //     // sa faca meciurile
    //     // sa bage castigatori la castigatori si pierzatori la pierzatori
    //     // sa elimine piezatorii gen pop la toti
    //     // sa faca meciurile din nou si tot asa
    // }

    return 0;
}