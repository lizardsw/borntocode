#include "push_swap.h"


void total_function(t_deq *A, t_deq *B)
{
	
}

void AtoB(t_deq *A, t_deq *B, int start, int end)
{
	int pivot1
	int pivot2

	setting_pivot(A, &pivot1, &pivot2);
	
	if (start)




}



void push_node(t_deq *A, t_deq *B, int number)
{	
	int pivot1;
	int pivot2;
	
	setting_pivot(A, &pivot1, &pivot2);
	show_deq(A);
	show_deq(B);
	ft_printf("\n");
	if (number < 1)
		return;
	if (A -> start -> index < pivot2)
	{
		ft_pb(B, A);
		swap_node(B, pivot2);
		push_node(A, B, --number);
	}
	else
	{
		ft_ra(A);
		push_node(A, B, --number);
	}
}

void swap_node(t_deq *B, int pivot1)
{
	if (B -> start -> index < pivot1)
		ft_rb(B);
}

void setting_pivot(t_deq *deq, int *pivot1, int *pivot2)
{
	int size;

	size = deq -> size;
	*pivot1 = size / 3;
	*pivot2 = (size / 3) * 2;
}

