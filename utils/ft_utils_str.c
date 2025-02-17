#include "../headers/push_swap.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}
char *ft_strdup(char *str)
{
	char	*dest, *tmp;
	size_t	len;

	len = ft_strlen(str);
	dest = (char *)malloc((len * sizeof(char)) + 1);
	if (!dest)
		return (0);
	tmp = dest;
	while (*str)
		*tmp++ = *str++;
	dest[len] = '\0';
	return (dest);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i = 0;
	int		j = 0;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
int	ft_atoi(char	*str)
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
	while (str[i] >='0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
	}
	return (res * sign);
}
int	ft_isdigit(char i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
