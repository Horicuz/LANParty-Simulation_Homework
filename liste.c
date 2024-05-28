#include "liste.h"

void addAtBeginning(Node **head, TEAM v) // add a team at the beginning of the list
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node **head, TEAM v) // add a team at the end of the list
{
	Node *aux = *head;
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	if (*head == NULL)
		addAtBeginning(head, v);
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL;
	}
}

void deleteNode(Node **head, TEAM v) // delete a team from the list
{
	if (*head == NULL)
		return;
	Node *headcopy = *head;
	if (strcmp(headcopy->val.name, v.name) == 0)
	{
		*head = (*head)->next;
		free(headcopy);
		return;
	}
	Node *prev = *head;
	while (headcopy != NULL)
	{
		if (strcmp(headcopy->val.name, v.name) != 0)
		{
			prev = headcopy;
			headcopy = headcopy->next;
		}
		else
		{
			prev->next = headcopy->next;
			free(headcopy);
			return;
		}
	}
}

void deleteMin(Node **head) // delete the team with the lowest number of points
{
	if (*head == NULL)
		return;
	Node *headcopy = *head;
	headcopy = headcopy->next;
	Node *min = *head;
	while (headcopy != NULL)
	{
		if (headcopy->val.teamPoints < min->val.teamPoints)
		{
			min = headcopy;
		}
		headcopy = headcopy->next;
	}
	deleteNode(head, min->val);
}

void printList(Node *head, FILE *output) // print the list
{
	Node *auxNode = head;
	while (auxNode != NULL)
	{
		fprintf(output, "%s\n", auxNode->val.name);
		auxNode = auxNode->next;
	}
}

void freeMem(Node **head) // free the memory
{
	while (*head != NULL)
	{
		Node *aux = *head;
		*head = (*head)->next;
		for (int j = 0; j < aux->val.playerCount; j++)
		{
			free(aux->val.players[j].firstName);
			free(aux->val.players[j].secondName);
		}
		free(aux->val.players);
		free(aux->val.name);
		free(aux);
	}
}
