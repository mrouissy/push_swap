#include "../headers/push_swap.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}
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
		exit(1);
	}
	while (str[i] >='0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
	}
	if((res * sign) < INT_MIN || (res * sign) > INT_MAX)
	{
		write(2,"Error limits\n",14);
		exit(1);
	}
	return (res * sign);
}
int	ft_isdigit(char i)
{
	if ((i >= '0' && i <= '9') || i == '-' || i == '+' )
		return (1);

	return (0);
}
