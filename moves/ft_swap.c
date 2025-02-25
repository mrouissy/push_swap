/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:12 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 14:53:14 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void ft_swap(t_node **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	t_node *first = *stack;
	t_node *second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_node **stack, int i)
{
	ft_swap(stack);
	if(i)
		write(1, "sa\n", 3);
}
void sb(t_node **stack, int i)
{
	ft_swap(stack);
	if(i)
		write(1, "sb\n", 3);
}
void ss(t_node **a,t_node **b, int i)
{
	sa(a,0);
	sb(b,0);
	if(i)
		write(1, "ss\n", 3);
}
