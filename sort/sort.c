#include "../headers/push_swap.h"


int is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return 1;
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return 0;
		stack = stack->next;
	}
	return 1;
}



void	sort_tree(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return;
	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;

	if (first > second && second > third && first > third)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
	else if (first > second && second > third)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (first > second && first > third)
		ra(stack, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 1);
}

void rank_stack(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		rank;

	tmp = stack;
	while (tmp)
	{
		rank = 1;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp->data > tmp2->data)
				rank++;
			tmp2 = tmp2->next;
		}
		tmp->index = rank;
		tmp = tmp->next;
	}
}
