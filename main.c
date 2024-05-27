#include "cozi.h"
#include "liste.h"
#include "stive.h"
#include "functions.h"
#include "BST.h"
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

    Node *aux = head;
    int round = 1;
    Queue *q = createQueue(); // the queue of matches

    MATCH m;
    while (aux != NULL) // create the first matches
    {
        m.team1 = aux;
        m.team2 = aux->next;
        enQueue(q, m);
        aux = aux->next->next;
    }

    Node *LoserStack = NULL;
    Node *WinnerStack = NULL;
    Node *newHead = NULL; // the list with the last 8 teams

    while (remainingTeams > 1)
    {
        fprintf(output, "\n--- ROUND NO:%d\n", round);
        while (!isEmptyQ(q))
        {
            m = deQueue(q);
            printMatch(m, output);
            if (m.team1->val.teamPoints > m.team2->val.teamPoints) // determine the winner and the loser
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

        deleteStack(&LoserStack); // eliminate the losers
        remainingTeams /= 2;
        fprintf(output, "\nWINNERS OF ROUND NO:%d\n", round);

        if (remainingTeams != 1)
        {
            round++;
            if (remainingTeams == 8) // create the list with the last 8 teams
            {
                while (!isEmpty(WinnerStack)) // create the following matches with the winners
                {
                    ;
                    m.team1 = popMove(&WinnerStack);
                    printWinner(m, output, 1);
                    m.team2 = popMove(&WinnerStack);
                    printWinner(m, output, 2);
                    enQueue(q, m);

                    addAtBeginning(&newHead, m.team1->val);
                    addAtBeginning(&newHead, m.team2->val);
                }
            }
            else
            {
                while (!isEmpty(WinnerStack))
                {
                    m.team1 = popMove(&WinnerStack);
                    printWinner(m, output, 1);
                    m.team2 = popMove(&WinnerStack);
                    printWinner(m, output, 2);
                    enQueue(q, m);
                }
            }
        }
        else
        {
            m.team1 = popMove(&WinnerStack);
            printWinner(m, output, 1); // print the winner
        }
    }

    if (task == 3)
    {
        freeMem(&newHead);
        deleteStack(&WinnerStack);
        deleteQueue(q);
        closeFiles(input1, input2, output);
        return 0;
    }

    // task 4
    fprintf(output, "\n--- FINAL STAGE\n");
    Node *auxNode = newHead;
    TreeNode *bst = newNode(auxNode->val); // create the binary search tree
    auxNode = auxNode->next;
    while (auxNode != NULL)
    {
        insertNode(&bst, auxNode->val);
        auxNode = auxNode->next;
    }

    printInorder(bst, output); // print the teams in the inorder traversal
}