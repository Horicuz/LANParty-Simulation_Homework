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

TEAM createTeam(FILE *file) // read the team info from the file
{
	TEAM t;
	char auxChar;
	float teamPoints = 0;

	fscanf(file, "%d", &t.playerCount);
	t.players = (PLAYER *)malloc(t.playerCount * sizeof(PLAYER));
	fscanf(file, "%c", &auxChar);
	t.name = (char *)malloc(100 * sizeof(char));

	while (fscanf(file, "%c", &auxChar) && auxChar != '\n')
	{
		t.name[strlen(t.name)] = auxChar;
	}

	t.name[strlen(t.name)] = '\0';

	for (int i = 0; i < t.playerCount; i++)
	{
		t.players[i].firstName = (char *)malloc(100 * sizeof(char));
		t.players[i].secondName = (char *)malloc(100 * sizeof(char));

		fscanf(file, "%s", t.players[i].firstName);
		fscanf(file, "%s", t.players[i].secondName);
		fscanf(file, "%d", &t.players[i].points);

		teamPoints += (float)t.players[i].points;
	}

	teamPoints /= (float)t.playerCount;
	t.teamPoints = teamPoints;

	return t;
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

void printList(Node *head, FILE *output)
{
	Node *auxNode = head;
	while (auxNode != NULL)
	{
		fprintf(output, "%s\n", auxNode->val.name);
		auxNode = auxNode->next;
	}
}

void freeMem(Node **head)
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
