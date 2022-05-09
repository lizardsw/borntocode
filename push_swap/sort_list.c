#include "push_swap.h"

void sort_index_deq(t_deq *deq)
{
	t_node *pt;
	t_node *ptr;

	pt = deq -> start;
	while (pt != NULL)
	{
		ptr = pt -> next;
		while (ptr != NULL)
		{
			if (pt -> number > ptr -> number && pt -> index < ptr -> index)
				node_index_swap(pt, ptr);
			ptr = ptr -> next;
		}
		pt = pt -> next;
	}
}

void node_index_swap(t_node *A, t_node *B)
{
	int temp;

	temp = A -> index;
	A -> index = B -> index;
	B -> index = temp;
}

