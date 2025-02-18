#ifndef push_swap_H
#define push_swap_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;


char	**ft_split(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);

node *add_new(int val);
void add_front(node **lst, node *new);
int	ft_isdigit(char i);
int is_int(char *str);
long	ft_atol(char	*str);

#endif
