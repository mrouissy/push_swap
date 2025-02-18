#include "../headers/push_swap.h"

node *add_new(int val)
{
	node *new;

	new = (node *)malloc(sizeof(node));
	new->data=val;
	new->next=NULL;
	return (new);
}
void add_front(node **lst, node *new)
{
	new->next = *lst;
	*lst = new;
}

