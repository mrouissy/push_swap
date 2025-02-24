/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:26:51 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 14:07:16 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int main(int ac, char **av)
{
    int i = 1, j = 0, valid = 0;
    t_node *stack_a = NULL;
    // t_node *stack_b = NULL;
    char **multi = NULL;

    if(ac > 1)
    {
        while(av[i])
        {
            valid = is_valid(av[i]);
            if(valid == 0)
            {
                write(2, "Error\n", 6);
                ft_lstclear(&stack_a);
                return(1);
            }
            else if(valid == 1)
            {
                if (!fill_stack(&stack_a, av[i]))
                {
                    ft_lstclear(&stack_a);
                    return(1);
                }
            }
            else
            {
                multi = ft_split(av[i], ' ');
                if (!multi)
                {
                    ft_lstclear(&stack_a);
                    return(1);
                }
                j = 0;
                while(j < valid)
                {
                    if (!fill_stack(&stack_a, multi[j]))
                    {
                        free_split(multi);
                        ft_lstclear(&stack_a);
                        return(1);
                    }
                    j++;
                }
                free_split(multi);
            }
            i++;
        }
    }
    // ft_push(&stack_a,&stack_b);
    // fill_stack(&stack_b,"11");
    // fill_stack(&stack_b,"12");
    // fill_stack(&stack_b,"12");
    // fill_stack(&stack_b,"12");
   // ft_swap(&stack_a,&stack_b);
   ft_rotate(&stack_a);
    printf("stack a\n");
    ft_printList(stack_a);
    ft_lstclear(&stack_a);
    // printf("stack b\n");
    // ft_printList(stack_b);
    // ft_lstclear(&stack_b);
    return 0;
}
