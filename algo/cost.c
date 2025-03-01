/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:20:22 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 11:21:56 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int calculate_cost(t_node *stack_a, t_node *stack_b, int size_b)
{
    int a;
    int b;
    int pb;
    int pt;
    int cost;

    b = size_b;
    a = lst_size(stack_a);
    pb = stack_b->pos;
    pt = stack_b->target->pos;

    if (pt > (a / 2) && pb <= (b / 2))
        cost = a - pt + pb;
    else if (pt <= (a / 2) && pb > (b / 2))
        cost = b - pb + pt;
    else if (pt > (a / 2) && pb > (b / 2))
        cost = (a - pt > b - pb ? a - pt : b - pb);
    else
        cost = (pt > pb ? pt : pb);

    return cost;
}

void fill_cost(t_node *stack_a, t_node *stack_b)
{
    int pb;
    int pt;
    int size_b;
    int size_a;

    size_a = lst_size(stack_a);
    size_b = lst_size(stack_b);
    while (stack_b)
    {
        pb = stack_b->pos;
        pt = stack_b->target->pos;

        if ((pb <= size_b / 2 && pt <= size_a / 2) || (pb > size_b / 2 && pt > size_a / 2))
        {
            if (pb <= size_b / 2)
                stack_b->cost = (pb > pt ? pb : pt);
            else
                stack_b->cost = (size_b - pb > size_a - pt ? size_b - pb : size_a - pt);
        }
        else
        {
            stack_b->cost = calculate_cost(stack_a, stack_b, size_b);
        }
        stack_b = stack_b->next;
    }
}

t_node *get_min_cost(t_node *stack)
{
    t_node *min;
    t_node *tmp;

    if (!stack)
        return NULL;

    min = stack;
    tmp = stack;

    while (tmp)
    {
        if (tmp->cost < min->cost)
            min = tmp;
        tmp = tmp->next;
    }

    return min;
}
