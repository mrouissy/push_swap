/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:21 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 14:16:20 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int is_valid(char *str)
{
	int i = 0, j = 0;
	char **res = ft_split(str, ' ');
	if (!res)
		return 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (ft_isdigit(res[i][j]) == 0)
			{
				free_split(res);
				return 0;
			}
			j++;
		}
		i++;
	}
	if (i == 0)
	{
		free_split(res);
		return 0;
	}
	free_split(res);
	return i;
}
// remove
void ft_printList(t_node *head)
{
	int i = 1;
	while(head)
	{
		printf ("%d->%d:%d\n",i++,head->index,head->data);
		head = head->next;
	}
}

int is_dup(t_node *stack,int data)
{
	while (stack)
	{
		if(stack->data == data)
			return 1;
		stack = stack->next;
	}
	return (0);
}
