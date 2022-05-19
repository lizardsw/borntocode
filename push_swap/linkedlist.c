#include "push_swap.h"

t_pocket	*new_pocket(t_deq *A, t_deq *B, t_deq *rule)
{
	t_pocket	*new;

	new = (t_pocket *)malloc(sizeof(t_pocket));
	if (new == NULL)
		return (NULL);
	new -> A = A;
	new -> B = B;
	new -> rule = rule;
	return (new);
}

t_deq	*new_deq(void)
{
	t_deq	*new;

	new = (t_deq *)malloc(sizeof(t_deq));
	if (new == NULL)
		return (NULL);
	new -> start = NULL;
	new -> end = NULL;
	new -> size = 0;
	return (new);
}

t_node	*new_node(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	new -> prev = NULL;
	new -> number = number;
	new -> index = 0;
	return (new);
}

void	delete_node(t_deq *deq, t_node *pt)
{
	t_node	*prev_pt;
	t_node	*next_pt;

	prev_pt = pt -> prev;
	next_pt = pt -> next;
	if (pt -> next == NULL)
		free(pop_back(deq));
	else if (pt -> prev == NULL)
		free(pop_front(deq));
	else
	{
		prev_pt -> next = next_pt;
		next_pt -> prev = prev_pt;
		pt -> next = NULL;
		pt -> prev = NULL;
		deq -> size--;
		free(pt);
	}
}

void	show_deq(t_deq *deq)
{
	t_node	*ptr;
	int		i;

	i = deq -> size;
	ptr = deq -> end;
	ft_printf("end ");
	while (i > 0)
	{
		ft_printf("%d(%d) - ", ptr->number, ptr -> index);
		ptr = ptr -> prev;
		i--;
	}
	ft_printf("start TOP ");
	ft_printf("%d\n", deq -> size);
}
