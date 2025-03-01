/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:20:29 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 11:20:30 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void push_all_to_b(t_node **a, t_node **b)
{
    int piv;
    if(lst_size(*a) > 3)
    {
        while(lst_size(*a) != 3)
        {
            rank_stack(*a);
            piv = lst_size(*a) / 2;
            while (*a && (*a)->index >= piv)
                ra(a, 1);
            pb(a, b, 1);
        }
    }
}

static void fill_pos(t_node *tmp)
{
    int i;
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

void algo(t_node **a, t_node **b)
{
    if(lst_size(*a) > 1)
    {
        push_all_to_b(a, b);
        sort_tree(a);
        while (*b)
        {
            fill_pos(*b);
            fill_pos(*a);
            target(*a, *b);
            fill_cost(*a, *b);
            apply_mouve(get_min_cost(*b), a, b);
            pa(a, b, 1);
        }
        finalize_stack_a(a);
    }

}
t_node	*ft_min_node(t_node *stack_a)
{
    t_node	*min_node;
    int		position;

    position = 0;
    min_node = stack_a;
    while (stack_a)
    {
        stack_a->pos = position++;
        if (stack_a->data < min_node->data)
            min_node = stack_a;
        stack_a = stack_a->next;
    }
    return (min_node);
}
void	finalize_stack_a(t_node **stack_a)
{
    t_node	*min_node;
    t_node	*temp;
    int		min_position;

    temp = *stack_a;
    min_node = ft_min_node(temp);
    min_position = min_node->pos;
    if (min_position <= lst_size(*stack_a) / 2)
    {
        while (min_position-- > 0)
            ra(stack_a, 1);
    }
    else
    {
        while (min_position++ < lst_size(*stack_a))
            rra(stack_a, 1);
    }
}



static void apply_rr(t_node *tomouve, t_node **stack_a, t_node **stack_b, int piva, int pivb)
{
    while ((*stack_b != tomouve && tomouve->pos < pivb)
        && (*stack_a != tomouve->target && tomouve->target->pos < piva))
        rr(stack_a, stack_b, 1);
}

static void apply_rrr(t_node *tomouve, t_node **stack_a, t_node **stack_b, int piva, int pivb)
{
    while ((*stack_b != tomouve && tomouve->pos >= pivb)
        && (*stack_a != tomouve->target && tomouve->target->pos >= piva))
        rrr(stack_a, stack_b, 1);
}

static void move_to_target(t_node **stack_a, t_node *target, int piva)
{
    while (*stack_a != target)
    {
        if (target->pos < piva)
            ra(stack_a, 1);
        else
            rra(stack_a, 1);
    }
}

static void move_to_tomouve(t_node **stack_b, t_node *tomouve, int pivb)
{
    while (*stack_b != tomouve)
    {
        if (tomouve->pos < pivb)
            rb(stack_b, 1);
        else
            rrb(stack_b, 1);
    }
}

void apply_mouve(t_node *tomouve, t_node **stack_a, t_node **stack_b)
{
    int piva;
    int pivb;

    fill_pos(*stack_a);
    fill_pos(*stack_b);
    piva = lst_size(*stack_a) / 2;
    pivb = lst_size(*stack_b) / 2;
    apply_rr(tomouve, stack_a, stack_b, piva, pivb);
    apply_rrr(tomouve, stack_a, stack_b, piva, pivb);
    move_to_target(stack_a, tomouve->target, piva);
    move_to_tomouve(stack_b, tomouve, pivb);
}
