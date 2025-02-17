#include "../headers/push_swap.h"
#include <stdio.h>

static char *join_args(char **str,int count)
{
	int i =0, j = 0;
	char *arg;
	char *args;

	args = " ";
	arg = NULL;
	while(i < count)
	{
		j = 0;
		while (str[i])
		{
			if(ft_isdigit(str[i][j]) == 1)
				arg[j] =str[i][j];
			else
				return (NULL);
		}
		arg[j++] = ' ';
		arg[j] = '\0';
		ft_strjoin(arg,args);
	}
	return (args);
}
int main(int ac,char **av)
{
	if(ac == 1)
		return(0);
	char *args =join_args(av,ac - 1);
	if (!args)
	{
		write(2,"Error\n",7);
		return (1);
	}
	printf("%s",args);

	return 0;
}

