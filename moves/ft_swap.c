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

void ft_swap(t_node **from, t_node **to)
{
	t_node *tmp1 = *from;
	t_node *tmp2 = *to;
	*from = (*from)->next;
	*to = (*to)->next;
	ft_add_front(from,tmp2);
	ft_add_front(to,tmp1);
}
