#include "push_swap.h"

void AtoB(t_pocket *pocket, int start, int end)
{
	int pivot[2];
	int range;
	int i;
	int j;
	
	i = 0;
	j = 0;
	range = setting_pivot(start, end, &pivot[0], &pivot[1]);
	//ft_printf("\n****************AtoB start!****************");
	//ft_printf("\nstart : %d, end : %d pivot1 : %d, pivot2 : %d\n",start, end, pivot1, pivot2);
	//ft_printf("(%d ~ %d) (%d ~ %d) (%d ~ %d)\n\n", start, pivot1, pivot1 + 1, pivot2, pivot2 + 1, end);
	if (range <= 2)
	{
		AtoB_small_sort(pocket, start, end);
	//	show_deq(pocket -> A);
	//	show_deq(pocket -> B);
		return;
	}
	while (range >= 1)
	{
		if (pocket -> A -> start -> index > pivot[1])
		{
			ft_rotate(pocket , 1);
			j++;
		}
		else
		{
			if (pocket -> A -> start -> index <= pivot[0])
				ft_push(pocket, 2);
			else
			{
				ft_push(pocket, 2);
				ft_rotate(pocket, 2);
				i++;
			}
		}
		range--;
	//	show_deq(pocket -> A);
	//	show_deq(pocket -> B);
	//	ft_printf("\n");
	}
	while (i != 0)
	{
		ft_revrotate(pocket, 2);
		i--;
	}
	while (j != 0)
	{
		ft_revrotate(pocket, 1);
		j--;
	}
	//ft_printf("\nreroate finished!\n\n");
	//show_deq(pocket -> A);
	//show_deq(pocket -> B);
	//ft_printf("\n");
	AtoB(pocket, pivot[1] + 1, end);
	BtoA(pocket, pivot[0] + 1, pivot[1]);
	BtoA(pocket, start, pivot[0]);
}

void BtoA(t_pocket *pocket, int start, int end)
{
	int pivot[2];
	int range;
	int i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	range = setting_pivot(start, end, &pivot[0], &pivot[1]);
	//ft_printf("\n******************BtoA start!********************");
	//ft_printf("\nstart : %d, end : %d pivot1 : %d, pivot2 : %d\n",start, end, pivot1, pivot2);
	//ft_printf("(%d ~ %d) (%d ~ %d) (%d ~ %d)\n\n", start, pivot1, pivot1 + 1, pivot2, pivot2 + 1, end);
	if (range <= 2)
	{
		BtoA_small_sort(pocket, start, end);
	//	show_deq(pocket -> A);
	//	show_deq(pocket -> B);
		return;
	}
	while (range >= 1)
	{
		if (pocket -> B -> start -> index <= pivot[0])
		{
			ft_rotate(pocket , 2);
			j++;
		}
		else
		{
			if (pocket -> B -> start -> index > pivot[1])
				ft_push(pocket, 1);
			else
			{
				ft_push(pocket, 1);
				ft_rotate(pocket, 1);
				i++;
			}
			k++;
		}
	//	show_deq(pocket -> A);
	//	show_deq(pocket -> B);
		range--;
	}
	//ft_printf("\nreroate finished!\n\n");
	//show_deq(pocket -> A);
	//show_deq(pocket -> B);
	
	AtoB(pocket, pivot[1] + 1, end);
	while (i != 0)
	{
		ft_revrotate(pocket, 1);
		i--;
	}
	AtoB(pocket, pivot[0] + 1, pivot[1]);
	while (j != 0)
	{
		ft_revrotate(pocket, 2);
		j--;
	}
	BtoA(pocket, start, pivot[0]);
}

int setting_pivot(int start, int end, int *pivot1, int *pivot2)
{
	int size;

	size = end - start;
	if (size + 1 == 3)
	{
		*pivot1 = start;
		*pivot2 = end - 1;
		return (size + 1);
	}
	*pivot1 = start + size / 3;
	*pivot2 = start + (size / 3) * 2;

	return (size + 1);
}

