/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:33 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 13:44:43 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_node *add_new(int val)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data=val;
	new->next=NULL;
	return (new);
}

int lst_size(t_node *lst)
{
    int i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return i;
}

t_node *ft_last(t_node *lst)
{
	while (lst)
	{
		if(!lst->next)
			return(lst);
		lst = lst->next;
	}
	return lst;
}

int ft_size(t_node *lst)
{
	int i = 0;
	while(lst)
	{
		i++;
		lst = lst->next;
	}
	return i;
}

void ft_add_back(t_node **lst, t_node *new)
{
	t_node *lt = NULL;
	if(lst)
	{
		if(*lst)
		{
			lt = ft_last(*lst);
			lt->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstclear(t_node **lst)
{
	t_node	*current;
	t_node	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int fill_stack(t_node **stack, char *value)
{
	long num = ft_atol(value);
	if (num == LONG_MAX)
		return 0;
	if(is_dup(*stack, (int)num) == 1)
		return 0;
	ft_add_back(stack, add_new((int)num));
	return 1;
}
void ft_add_front(t_node **head,t_node *new)
{
	new->next = *head;
	*head = new;
}
