/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:12:30 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/20 13:19:35 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void free_split(char **split)
{
	int i = 0;

	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void handle_error(t_node **stack_a)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack_a);
}
