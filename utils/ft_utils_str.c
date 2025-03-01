/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:29 by mrouissy          #+#    #+#             */
/*   Updated: 2025/02/27 10:57:06 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

long	ft_atol(char	*str)
{
	int	i;
	int	sign;
	long	res;

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
		return (LONG_MAX);
	}
	while (str[i] >='0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
	}
	if ((sign * res ) > INT_MAX || (sign * res) < INT_MIN || str[i] != '\0')
		return (LONG_MAX);
	return (res * sign);
}
int	ft_isdigit(char i)
{
	if (i >= '0' && i <= '9')
		return (1);

	return (0);
}
