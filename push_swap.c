/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:20:49 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 11:20:50 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int process_single_argument(t_node **stack_a, t_node **stack_b, char *arg)
{
	if (!fill_stack(stack_a, arg))
	{
		handle_error(stack_a, stack_b);
		return 0;
	}
	return 1;
}

int process_multiple_arguments(t_node **stack_a, t_node **stack_b, char *arg)
{
	char **multi = ft_split(arg, ' ');
	int j = 0;

	if (!multi)
	{
		handle_error(stack_a, stack_b);
		return 0;
	}
	while (multi[j])
	{
		if (!fill_stack(stack_a, multi[j]))
		{
			free_split(multi);
			handle_error(stack_a, stack_b);
			return 0;
		}
		j++;
	}
	free_split(multi);
	return 1;
}

int process_argument(t_node **stack_a, t_node **stack_b, char *arg)
{
	int valid = is_valid(arg);

	if (valid == 0)
	{
		handle_error(stack_a, stack_b);
		return 0;
	}
	else if (valid == 1)
	{
		return process_single_argument(stack_a, stack_b, arg);
	}
	else
	{
		return process_multiple_arguments(stack_a, stack_b, arg);
	}
}

int main(int ac, char **av)
{
    int i = 1;
    t_node *stack_a = NULL, *stack_b = NULL;
    if (ac > 1)
    {
        while (av[i])
        {
            if (!process_argument(&stack_a,&stack_b, av[i]))
                return 1;
            i++;
        }
        if (is_sorted(stack_a))
            return 0;

        int size = lst_size(stack_a);
        if (size == 2)
            sa(&stack_a, 1);
        else if (size == 3)
            sort_tree(&stack_a);
        else
            algo(&stack_a, &stack_b);
    }
    ft_lstclear(&stack_a);
    ft_lstclear(&stack_b);
    return 0;
}
//check leaks in without args
// test 119 and 71
//2147483647 9487 0 -2147483647 -2147483648 ==>119
// 0 2147483647 9487 -2147483647 -2147483648 ==>71
