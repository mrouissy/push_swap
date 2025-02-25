#include "headers/push_swap.h"

int process_argument(t_node **stack_a, char *arg)
{
	int valid = is_valid(arg);
	char **multi;
	int j;

	if (valid == 0)
	{
		handle_error(stack_a);
		return 0;
	}
	else if (valid == 1)
	{
		if (!fill_stack(stack_a, arg))
		{
			handle_error(stack_a);
			return 0;
		}
	}
	else
	{
		multi = ft_split(arg, ' ');
		if (!multi)
		{
			handle_error(stack_a);
			return 0;
		}
		j = 0;
		while (j < valid)
		{
			if (!fill_stack(stack_a, multi[j]))
			{
				free_split(multi);
				handle_error(stack_a);
				return 0;
			}
			j++;
		}
		free_split(multi);
	}
	return 1;
}

int main(int ac, char **av)
{
	int i = 1;
	t_node *stack_a = NULL;

	if (ac > 1)
	{
		while (av[i])
		{
			if (!process_argument(&stack_a, av[i]))
				return 1;
			i++;
		}
	}
	return 0;
}
