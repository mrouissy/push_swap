/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:22:20 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 11:48:08 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static t_node *find_smallest_node(t_node *a)
{
	t_node *current = a;
	t_node *smallest = a;

	while (current)
	{
		if (current->index < smallest->index)
		{
			smallest = current;
		}
		current = current->next;
	}

	return smallest;
}

static t_node *begest_small(t_node *a, t_node *b)
{
	t_node *current = a;
	t_node *best_match = NULL;

	while (current)
	{
		if (current->data > b->data && (!best_match || current->data < best_match->data))
		{
			best_match = current;
		}
		current = current->next;
	}

	if (!best_match)
	{
		best_match = find_smallest_node(a);
	}

	return best_match;
}

void target(t_node *a,t_node *b)
{
	t_node *tmp = b;
	while (tmp)
	{
		tmp->target = begest_small(a,tmp);
		tmp = tmp->next;
	}
}
