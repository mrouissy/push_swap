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
    head->next = NULL;
	ft_add_back(stack,head);
}

void ft_rrotate(t_node **stack)
{
    if (!stack || !*stack)
        return;
    t_node *head = *stack;
    t_node *tail = ft_last(head);
    if (head == tail)
        return;
    while (head->next && head->next->next)
        head = head->next;
    head->next = NULL;
    ft_add_front(stack, tail);
}
void ra(t_node **a, int i)
{
    ft_rotate(a);
    if(i)
        write(1, "ra\n", 3);
}
void rb(t_node **b, int i)
{
    ft_rotate(b);
    if(i)
        write(1, "rb\n", 3);
}
void rr(t_node **a, t_node **b, int i)
{
    ra(a,0);
    rb(b,0);
    if(i)
        write(1, "rr\n", 3);
}
void rra(t_node **a, int i)
{
    ft_rrotate(a);
    if(i)
        write(1, "rra\n", 4);
}
void rrb(t_node **b, int i)
{
    ft_rrotate(b);
    if(i)
        write(1, "rrb\n", 4);
}
void rrr(t_node **a, t_node **b, int i)
{
    rra(a,0);
    rrb(b,0);
    if(i)
        write(1, "rrr\n", 4);
}
