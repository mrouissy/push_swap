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

// void sort_tree(t_node **stack)
// {
//     while (!is_sorted(*stack))
//     {
//         int a = (*stack)->data;
//         int b = (*stack)->next->data;
//         int c = (*stack)->next->next->data;

//         if (a > b && a > c)
//             ra(stack, 1);
//         else if (b > a && b > c)
//             rra(stack, 1);
//         else if (a > b)
//             sa(stack, 1);
//     }
// }

void	sort_tree(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack, 1);
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
