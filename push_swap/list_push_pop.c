#include "push_swap.h"

void	push_front(t_deq *deq, t_node *node)
{
	if (deq -> size == 0)
	{
		deq -> start = node;
		deq -> end = node;
		deq -> size++;
		return ;
	}
	deq-> start -> prev = node;
	node -> next = deq -> start;
	deq -> start = node;
	deq -> size++;
}

void	push_back(t_deq *deq, t_node *node)
{
	if (deq -> size == 0)
	{
		deq -> start = node;
		deq -> end = node;
		deq -> size++;
		return ;
	}
	deq -> end -> next = node;
	node -> prev = deq -> end;
	deq -> end = node;
	deq -> end -> next = NULL;
	deq -> size++;
}

t_node	*pop_front(t_deq *deq)
{
	t_node	*temp;

	if (deq -> size == 0)
		return (NULL);
	if (deq -> size == 1)
	{
		temp = deq -> start;
		deq -> start = NULL;
		deq -> end = NULL;
		temp -> next = NULL;
		temp -> prev = NULL;
		deq -> size--;
		return (temp);
	}
	temp = deq -> start;
	deq -> start -> next -> prev = NULL;
	deq -> start = deq -> start -> next;
	temp -> next = NULL;
	temp -> prev = NULL;
	deq -> size--;
	return (temp);
}

t_node	*pop_back(t_deq *deq)
{
	t_node	*temp;

	if (deq -> size == 0)
		return (NULL);
	if (deq -> size == 1)
	{
		temp = deq -> end;
		deq -> end = NULL;
		deq -> start = NULL;
		deq -> size--;
		temp -> prev = NULL;
		temp -> next = NULL;
		return (temp);
	}
	temp = deq -> end;
	deq -> end -> prev -> next = NULL;
	deq -> end = deq -> end -> prev;
	temp -> prev = NULL;
	temp -> next = NULL;
	deq -> size--;
	return (temp);
}
