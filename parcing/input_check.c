/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:21 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 10:59:51 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int check_isdig(char *str)
{
	int i = 0;

	if(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int is_valid(char *str)
{
	int i = 0;
	char **res = ft_split(str, ' ');
	if (!res)
		return 0;
	while (res[i])
	{
		if(!check_isdig(res[i]))
		{
			free_split(res);
			return 0;
		}
		i++;
	}
	free_split(res);
	return i;
}
// remove
void ft_printList(t_node *head)
{
	//int i = 1;
	while(head)
	{
		//printf ("%d->%d:%d--tar-->%d\n", i++, head->index, head->data, head->target ? head->target->data : -1);
		printf("%d\n",head->data);
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
