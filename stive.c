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

void pop(Node **top) // deletes the top element
{
	Node *temp;
	if (isEmpty(*top))
	{
		printf("Stiva goala\n");
		exit(1);
	}
	temp = *top;
	*top = (*top)->next;
	free(temp);
}

Node *popMove(Node **top) // returns the node that was popped
{
	Node *temp;
	if (isEmpty(*top))
	{
		printf("Stiva goala\n");
		exit(1);
	}
	temp = *top;
	*top = (*top)->next;
	return temp;
}

void push(Node **top, Node *n)
{
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
