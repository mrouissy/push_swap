
#include "../headers/push_swap.h"

void push_all_b(t_node **a, t_node **b)
{
	//list size
	//piv = lis / 2 + if impair
	// push all node had rank <  piv
}

void turk(t_node **a, t_node **b)
{
	printf("stack a before sort ----\n");
	ft_printList(*a);
	printf("--------------\nstack a after sorted-------\n");

	//sort_tree(&stack_a);
	rank_stack(*a);
	ft_printList(*a);
	printf("------------------\n");
	ft_lstclear(a);
}
