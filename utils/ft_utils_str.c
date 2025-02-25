/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:29 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/20 13:25:56 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}
//./push_swap 4+5+6+7 error must hnadel
long	ft_atol(char	*str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13) || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if(str[i] == '-' || str[i] == '+')
	{
		write(2,"Error sign\n",12);
		return (0);
	}
	while (str[i] >='0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
	}
	return (res * sign);
}
int	ft_isdigit(char i)
{
	if ((i >= '0' && i <= '9') || i == '-' || i == '+' )
		return (1);

	return (0);
}
