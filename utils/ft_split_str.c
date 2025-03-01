/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:27 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/20 13:58:32 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int ft_wc(char *str)
{
	int i;
	int wc;
	int in_word;

	i = 0;
	wc = 0;
	in_word = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (!in_word)
			{
				wc++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (wc);
}


int ft_strlen(char *str, int j)
{
	int i;

	i = j;
	while (str[i])
		i++;
	return (i);
}

static char *ft_strdup_word(char *str, char c, int *index)
{
	int len;
	char *word;

	len = ft_strlen(str, *index);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	int i = 0;
	while (str[*index] && str[*index] != c)
		word[i++] = str[(*index)++];
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str, char c)
{
	int i = 0;
	int j = 0;
	char **res;

	res = (char **)malloc((ft_wc(str) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = ft_strdup_word(str, c, &i);
			if (!res[j])
			{
				free_split(res);
			}
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
