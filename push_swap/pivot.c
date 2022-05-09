#include "push_swap.h"

void AtoB(t_pocket *pocket, int start, int end)
{
	int pivot1;
	int pivot2;
	int range;
	int i;
	
	i = 0;
	range = setting_pivot(start, end, &pivot1, &pivot2);
	ft_printf("A pivot1 : %d, pivot2 : %d\n", pivot1, pivot2);
	if (range <= 1)
		return;
	while (range >= 1)
	{
		if (pocket -> A -> start -> index > pivot2)
			ft_rotate(pocket , 1);
		else
		{
			if (pocket -> A -> start -> index <= pivot1)
				ft_push(pocket, 2);
			else
			{
				ft_push(pocket, 2);
				ft_rotate(pocket, 2);
				i++;
			}
		}
		range--;
		show_deq(pocket -> A);
		show_deq(pocket -> B);
		ft_printf("\n");
	}
	while (i != 0)
	{
		ft_revrotate(pocket, 2);
		i--;
	}
	show_deq(pocket -> A);
	show_deq(pocket -> B);
	ft_printf("\n");
	AtoB(pocket, pivot2 + 1, end);
	BtoA(pocket, pivot1 + 1, pivot2);
	BtoA(pocket, start, pivot1);
}

void BtoA(t_pocket *pocket, int start, int end)
{
	int pivot1;
	int pivot2;
	int range;
	int i;
	
	range = setting_pivot(start, end, &pivot1, &pivot2);
	ft_printf("B pivot1 : %d, pivot2 : %d\n", pivot1, pivot2);
	if (range <= 1)
		return;
	while (range >= 1)
	{
		if (pocket -> A -> start -> index < pivot1)
			ft_rotate(pocket , 2);
		else
		{
			if (pocket -> A -> start -> index >= pivot2)
				ft_push(pocket, 1);
			else
			{
				ft_push(pocket, 1);
				ft_rotate(pocket, 1);
				i++;
			}
		}
		range--;
	}
	while (i != 0)
	{
		ft_revrotate(pocket, 1);
		i--;
	}
	BtoA(pocket, start, pivot1);
	AtoB(pocket, pivot1 + 1, pivot2);
	AtoB(pocket, pivot2 + 1, end);
}


int setting_pivot(int start, int end, int *pivot1, int *pivot2)
{
	int size;

	size = end - start;
	*pivot1 = start + size / 3;
	*pivot2 = start + (size / 3) * 2;

	return (size + 1);
}

