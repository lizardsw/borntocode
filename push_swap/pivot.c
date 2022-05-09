#include "push_swap.h"

void AtoB(t_pocket *pocket, int start, int end)
{
	int pivot1;
	int pivot2;
	int range;
	
	range = setting_pivot(start, end, &pivot1, &pivot2);
	ft_printf("pivot1 : %d, pivot2 : %d\n", pivot1, pivot2);
	if (range <= 1)
		return;
	while (range >= 1)
	{
		if (pocket -> A -> start -> index > pivot2)
			ft_rotate(pocket , 1);
		else
		{
			if (pocket -> A -> start -> index <= pivot1)
				ft_rotate(pocket, 2);
			else
			{
				ft_push(pocket, 2);
				ft_rotate(pocket, 2);
			}
		}
		range--;
	}
	AtoB(pocket, pivot2 + 1, end);
	/*
	BtoA(A, B, pivot1 + 1, pivot2);
	BtoA(A, B, start, pivot1);
	*/
}

void BtoA(t_deq *A, t_deq *B, int start, int end)
{
	int pivot1;
	int pivot2;
	int range;
	
	range = start - end + 1;
	setting_pivot(start, end, &pivot1, &pivot2);
	if (range <= 1)
		return;
	while (range >= 1)
	{
		if (A -> start -> index > pivot2)
			ft_rb(A);
		else
		{
			if (A -> start -> index <= pivot1)
				ft_pa(B, A);
			else
			{
				ft_pa(B, A);
				ft_ra(B);
			}
		}
		range--;
	}
}

int setting_pivot(int start, int end, int *pivot1, int *pivot2)
{
	int size;

	size = end - start;
	*pivot1 = start + size / 3;
	*pivot2 = start + (size / 3) * 2;

	return (size + 1);
}

