#ifndef push_swap_H
#define push_swap_H

#include <stdlib.h>
#include <unistd.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;


char	**ft_split(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

node *add_new(int val);
void add_front(node **lst, node *new);
int	ft_isdigit(char i);

#endif
