#include "../headers/push_swap.h"


static int find_min_position(t_node *a)
{
	t_node *current = a;
	int min_index = INT_MAX;
	int min_position = 0;
	int position = 0;

	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}

	return min_position;
}


static void move_min_to_top(t_node **a, int min_position)
{
	int size = lst_size(*a);
	int i;

	if (min_position <= size / 2) {
		i = 0;
		while (i < min_position) {
			ra(a, 1);
			i++;
		}
	} else {
		i = 0;
		while (i < size - min_position) {
			rra(a, 1);
			i++;
		}
	}
}
static void push_all_b(t_node **a, t_node **b)
{
	if(lst_size(*a) > 3)
	{
		while (lst_size(*a) != 3)
		{
			int min_position = find_min_position(*a);
			move_min_to_top(a, min_position);
			pb(a, b, 1);
			if (*a == NULL)
				break;
		}
	}

}
static void push_all_a(t_node **a, t_node **b)
{
	while (*b)
	{
		pa(a, b, 1);
	}
}
void algo(t_node **a, t_node **b)
{
    //printf("stack a before push ----\n");
    // ft_printList(*a);
    // printf("stack b before push ----\n");
    // printf("--------------\nstack a after sorted-------\n");
    if(lst_size(*a) > 1)
	{
		push_all_b(a, b);
		if(lst_size(*a) == 3)
			sort_tree(a);
		if(lst_size(*b) != 0)
			push_all_a(a, b);
	}
    //ft_printList(*a);
    // printf("------------------\nstack b after sorted-------\n");
    // ft_printList(*b);
    ft_lstclear(a);
	ft_lstclear(b);
}

