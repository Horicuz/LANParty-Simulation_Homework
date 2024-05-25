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

    // task 1
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

    if (task == 1)
    {
        printList(head, output);
        freeMem(&head);
        closeFiles(input1, input2, output);
        return 0;
    }

    // task 2
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

    if (task == 2)
    {
        printList(head, output);
        freeMem(&head);
        closeFiles(input1, input2, output);
        return 0;
    }

    // task 3
    printList(head, output);
    fprintf(output, "\n");
    fprintf(output, "--- Round NO:1\n");

    Node *aux34 = head;
    int round = 1;
    Queue *q = createQueue(); // the queue of matches

    while (aux34 != NULL)
    {
        MATCH m;
        m.team1 = aux34;
        m.team2 = aux34->next;
        fprintf(output, "%s%s", m.team1->val.name, m.team2->val.name);
        // for (int i = 1; i <= 33 - strlen(m.team1->val.name); i++)
        //     fprintf(output, " ");
        // fprintf(output, "-");
        // for (int i = 1; i <= 33 - strlen(m.team2->val.name); i++)
        //     fprintf(output, " ");
        // fprintf(output, "%s\n", m.team2->val.name);

        enQueue(q, m);
        aux34 = aux34->next->next;
    }

    Node *LoserStack = NULL;
    Node *WinnerStack = NULL;
    Node *newHead; // the list with the last 8 teams

    while (remainingTeams > 1)
    {
        while (!isEmptyQ(q))
        {
            MATCH m = deQueue(q);
            if (m.team1->val.teamPoints >= m.team2->val.teamPoints)
            {
                (m.team1->val.teamPoints)++;
                push(&WinnerStack, m.team1);
                push(&LoserStack, m.team2);
            }
            else
            {
                (m.team2->val.teamPoints)++;
                push(&WinnerStack, m.team2);
                push(&LoserStack, m.team1);
            }
        }

        deleteStack(&LoserStack);
        remainingTeams /= 2;
        round++;
        printf("--- Round NO:%d\n", round);
        if (remainingTeams == 8)
        {
            while (!isEmpty(WinnerStack))
            {
                MATCH m;
                Node *temp = popMove(&WinnerStack);
                addAtBeginning(&newHead, temp->val);
                m.team1 = temp;
                fprintf(output, "%s ", m.team1->val.name);
                printf("%f\n", m.team1->val.teamPoints);
                temp = popMove(&WinnerStack);
                addAtBeginning(&newHead, temp->val);
                m.team2 = temp;
                printf("%s%s", m.team1->val.name, m.team2->val.name);
                enQueue(q, m);
            }
            // create the list with the last 8 teams
        }
        else
            while (!isEmpty(WinnerStack))
            {
                MATCH m;
                Node *temp = popMove(&WinnerStack);
                m.team1 = temp;
                temp = popMove(&WinnerStack);
                m.team2 = temp;
                enQueue(q, m);
            }
    }

    return 0;
}