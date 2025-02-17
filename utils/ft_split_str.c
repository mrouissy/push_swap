#include "../headers/push_swap.h"

static int ft_wc(char *str)
{
	int i = 0, wc = 0, in_word = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
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
	while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
	{
		i++;
		len++;
	}
	return (len);
}

char **ft_split(char *str)
{
	int i = 0, j = 0, k, inword = 0;
	char **res = (char **)malloc((ft_wc(str)) * sizeof(char *));
	if (!res)
		return (0);
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			if (!inword)
			{
				res[j] = (char *)malloc(1000);
				if (!res[j])
					return (0);
				k = 0;
				while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
					res[j][k++] = str[i++];
				res[j++][k] = '\0';
				inword = 1;
				}
		}
		else
		{
			inword = 0;
			i++;
		}
	}
	res[j] = 0;
	return (res);
}
