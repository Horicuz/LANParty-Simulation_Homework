#include "cozi.h"

Queue *createQueue() // creare coada
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue));
	if (q == NULL)
		return NULL;
	q->front = q->rear = NULL;
	return q;
}

void enQueue(Queue *q, MATCH v) // adaugare in coada
{
	MatchNode *newNode = (MatchNode *)malloc(sizeof(MatchNode));
	newNode->val = v;
	newNode->next = NULL;
	if (q->rear == NULL)
		q->rear = newNode;
	else
	{
		(q->rear)->next = newNode;
		(q->rear) = newNode;
	}
	if (q->front == NULL)
		q->front = q->rear;
}

MATCH deQueue(Queue *q) // extragere din coada
{
	MatchNode *aux;
	MATCH d;
	if (isEmptyQ(q))
	{
		printf("Coada goala\n");
		exit(1);
	};

	aux = q->front;
	d = aux->val;
	q->front = (q->front)->next;
	return d;
}

int isEmptyQ(Queue *q) // verificare coada goala
{
	return (q->front == NULL);
}

void deleteQueue(Queue *q) // stergere coada
{
	MatchNode *aux;
	while (!isEmptyQ(q))
	{
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}
