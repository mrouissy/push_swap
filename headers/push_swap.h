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

// linked list
typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

// void 	add_front(t_node **lst, t_node *new);
int  fill_stack(t_node **stack, char *value);
void ft_add_back(t_node **lst, t_node *new);
void ft_add_front(t_node **lst, t_node *new);
void ft_printList(t_node *head);
void ft_lstclear(t_node **lst);
t_node *add_new(int val);
void ft_push(t_node **from, t_node **to);
t_node *ft_last(t_node *lst);

void ft_swap(t_node **from, t_node **to);
void ft_rotate(t_node **stack);
void ft_rrotate(t_node **stack);

// functions
void free_split(char **split);
size_t ft_strlen(char *str);
char **ft_split(char *str, char c);
long ft_atol(char *str);
int ft_isdigit(char i);
int is_int(char *str);
int is_int(char *str);
int is_valid(char *str);

#endif
