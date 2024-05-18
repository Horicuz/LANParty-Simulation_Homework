#include "liste.h"

void addAtBeginning(Node **head, TEAM v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node **head, TEAM v)
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

void deleteNode(Node **head, TEAM v)
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

TEAM createTeam(FILE *file)
{
	TEAM t;
	char auxChar;

	fscanf(file, "%d", &t.playerCount);
	t.players = (PLAYER *)malloc(t.playerCount * sizeof(PLAYER));

	fscanf(file, "%c", &auxChar);

	t.name = (char *)malloc(100 * sizeof(char));
	fgets(t.name, 100, file);

	for (int i = 0; i < t.playerCount; i++)
	{

		t.players[i].firstName = (char *)malloc(100 * sizeof(char));
		t.players[i].secondName = (char *)malloc(100 * sizeof(char));

		fscanf(file, "%s", t.players[i].firstName);
		fscanf(file, "%s", t.players[i].secondName);
		fscanf(file, "%d", &t.players[i].points);
	}

	return t;
}
