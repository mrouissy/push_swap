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
	int i = 0, wc = 0, in_word = 0;
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

static int ft_wordlen(char *str, int i)
{
	int len = 0;
	while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
	{
		i++;
		len++;
	}
	return (len);
}

char **ft_split(char *str, char c)
{
	int i = 0, j = 0, k, inword = 0;
	char **res = (char **)malloc((ft_wc(str) + 1) * sizeof(char *));
	if (!res)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!inword)
			{
				res[j] = (char *)malloc(ft_wordlen(str, i) + 1);
				if (!res[j])
				{
					while (--j >= 0)
						free(res[j]);
					free(res);
					return (NULL);
				}
				k = 0;
				while (str[i] && str[i] != c)
					res[j][k++] = str[i++];
				res[j][k] = '\0';
				j++;
				inword = 1;
			}
		}
		else
		{
			inword = 0;
			i++;
		}
	}
	res[j] = NULL;
	return (res);
}
