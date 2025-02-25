/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:43 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/23 13:57:47 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap_H
#define push_swap_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
//to remove
#include <stdio.h>

// linked list struct----------//
typedef struct s_node
{
	int data;
	int index;//rank
	struct s_node *next;

} t_node;
//------------------------------//

// linked list functions -------------------//
int  fill_stack(t_node **stack, char *value);
void ft_add_back(t_node **lst, t_node *new);
void ft_add_front(t_node **lst, t_node *new);
void ft_printList(t_node *head);
void ft_lstclear(t_node **lst);
t_node *add_new(int val);
void ft_push(t_node **from, t_node **to);
t_node *ft_last(t_node *lst);
int is_dup(t_node *stack,int data);
//------------------------------------------//

// mouves---------------------------//
void sb(t_node **stack, int i);
void sa(t_node **stack, int i);
void ss(t_node **a,t_node **b, int i);
void pa(t_node **a, t_node **b, int i);
void pb(t_node **a, t_node **b, int i);
void ra(t_node **a, int i);
void rb(t_node **b, int i);
void rr(t_node **a, t_node **b, int i);
void rra(t_node **a, int i);
void rrb(t_node **b, int i);
void rrr(t_node **a, t_node **b, int i);
//--------------------------------//

//sort -------------------------//
int is_sorted(t_node *stack);
void sort_tree(t_node **stack);
void rank_stack(t_node *stack);
//------------------------------//

// str functions-----------------//
void free_split(char **split);
void handle_error(t_node **stack_a);
size_t ft_strlen(char *str);
char **ft_split(char *str, char c);
long ft_atol(char *str);
int ft_isdigit(char i);
int is_valid(char *str);
//---------------------------------//
#endif
