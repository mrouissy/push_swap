/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:14 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/19 14:32:15 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
void ft_rotate(t_node **stack)
{
	if (!stack || !*stack)
		return;
	t_node *head = *stack;
	*stack = (*stack)->next;
	ft_add_back(stack,head);
}
void ft_rrotate(t_node **stack)
{
	if (!stack || !*stack)
		return;
	t_node *head = *stack;
	t_node *tail = ft_last(head);

	while (head->next)
		head=head->next;
	head->next=NULL;
	ft_add_front(stack, tail);
}
