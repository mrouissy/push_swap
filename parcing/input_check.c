#include "../headers/push_swap.h"
#include <stdio.h>
int is_valid(char *str)
{
	int len = 0, i = 0, j = 0;
	char **res =ft_split(str, ' ');//check if failed
	if(!res)
		write(2,"Error split\n",13);
	while(res[len])
		len++;
	if(len > 1)
	{
		while(res[i])
		{
			j = 0;
			while(res[i][j])
			{
				if(ft_isdigit(res[i][j]) == 0)
				{
					write(2,"Error is not a digit2\n",23);
					exit(1);
					//return(0);
				}
				j++;
			}
			i++;
		}
		return(len);
	}
	else
	{
		while(res[0][j])
		{
			if(ft_isdigit(res[0][j]) == 0)
			{
				write(2,"Error is not a digit1\n",23);
				exit(1);
				//return(0);
			}
			j++;
		}
	}
	return (1);
}

int is_int(char *str)
{
	int len = ft_strlen(str);
	if(len > 11)
	{
		return(0);
	}
	return(1);
}

int main(int ac, char **av)
{
	int i = 1,j =0, valid = 0,k = 0;
	//stac a b
	int *stac_a = malloc(6 *sizeof(int));

	char **multi = NULL;
	if(ac > 1)
	{
		while(av[i])
		{
			valid = is_valid(av[i]);
			k = 0;
			if(valid == 0)
			{
				write(2,"Error\n",7);
				return(1);
			}
			else if(valid == 1)
			{
				stac_a[k] = (int)ft_atol(av[i]);
			}
			else
			{
				j =0;
				multi = ft_split(av[i], ' ');//check if failed
				while(j < valid)
					stac_a[k++] = (int)ft_atol(multi[j++]);
				// j = 0;
				// while (multi[j])
				// 	free(multi[j++]);
				// free(multi);
			}
			i++;
		}
	}
	i = 0;
	while(i <6)
		printf("%d\n",stac_a[i++]);
	return 0;
}

