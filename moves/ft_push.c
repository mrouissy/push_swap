/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:05 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 14:24:44 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void ft_push(t_node **from, t_node **to)
{
	t_node *temp = *from;
	if (!from || !*from)
		return;
	*from = (*from)->next;
	temp->next = NULL;
	if (!*to)
		*to = temp;
	else
		ft_add_front(to, temp);
}
void pa(t_node **a, t_node **b, int i)
{
	ft_push(b, a);
	if(i)
		write(1, "pa\n", 3);
}
void pb(t_node **a, t_node **b, int i)
{
	ft_push(a, b);
	if(i)
		write(1, "pb\n", 3);
}

