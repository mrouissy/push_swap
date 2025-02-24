/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:21 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 14:16:20 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdio.h>

int is_valid(char *str)
{
    int len = 0, i = 0, j = 0;
    int return_value;
    char **res = ft_split(str, ' ');

    if(!res)
        return 0;

    while(res[len])
        len++;

    if(len > 1)
    {
        while(res[i])
        {
            j = 0;
            while(res[i][j])
            {
                if(ft_isdigit(res[i][j]) == 0)
                {
                    free_split(res);
                    return 0;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        while(res[0][j])
        {
            if(ft_isdigit(res[0][j]) == 0)
            {
                free_split(res);
                return 0;
            }
            j++;
        }
    }
    return_value = (len > 1) ? len : 1;
    free_split(res);
    return return_value;
}

int is_int(char *str)
{
	int len = ft_strlen(str);
	if(len > 11)
	{
		return(0);
	}
	return(1);
}
void ft_printList(t_node *head)
{
    int i = 1;
	while(head)
	{
        printf ("%d:%d\n",i++,head->data);
		head = head->next;
	}
}


