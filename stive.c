#include "stive.h"

int isEmpty(Node *top)
{
	return top == NULL;
}

void deleteStack(Node **top)
{
	Node *temp;
	while ((*top) != NULL)
	{ // !isEmpty(*top)
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

TEAM pop(Node **top)
{
	if (isEmpty(*top))
	{
		printf("Stiva goala\n");
		exit(1);
	}
	Node *temp = (*top);
	TEAM aux = temp->val;
	*top = (*top)->next;
	free(temp);
	return aux;
}

void push(Node **top, Node *n)
{
	// Node *newNode = (Node *)malloc(sizeof(Node));
	// newNode->val = v;
	// newNode->next = *top;
	// *top = newNode;

	n->next = *top;
	*top = n;
}

TEAM top(Node *top)
{
	if (isEmpty(top))
	{
		printf("Stiva goala\n");
		exit(1);
	}
	return top->val;
}
