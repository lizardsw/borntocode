#include "push_swap.h"

void AtoB_small_sort(t_pocket *pocket, int start, int end)
{
	int range;

	range = end - start + 1;
	if (range == 2)
	{	
		if (pocket -> A -> start -> index == end)
			ft_swap(pocket, 1);
	}
	if (range == 3)
	{
		
	}
}

void BtoA_small_sort(t_pocket *pocket, int start, int end)
{
	int range;

	range = end - start + 1;
	if (range == 1)
		ft_push(pocket, 1);
	else if (range == 2)
	{
		if (pocket -> B -> start -> index == start)
			ft_swap(pocket, 2);
		ft_push(pocket, 1);
		ft_push(pocket, 1);
	}
}
/*
void three_sort(t_pocket *pocket, int start, int end)
{
	int middle;

	middle = start + 1;
	if (pocket -> A -> start == start)
	{
		if (pocket -> A -> start -> next == middle)
			return
		else
		{
			ft_rotate(pocket, 1);
			ft_swap(pocket, 1);
			ft_revrotate(pocket, 1);
		}
	}
	else if (pocket -> A -> start == middle)
	{
		if (pocket -> A -> start -> next == start)
			ft_swap(pocket, 1);
		else
		{
			ft_rotate(pocket, 1);
			ft_swap(pocket, 1);
			ft_revrotate(pocket, 1);
			ft_swap(pocket, 1);
		}
	}
	else 
	{
		if (pocket -> A -> start -> next == start)
		{
			ft_swap(pocket, 1);
			ft_rotate(pocket, 1);
			ft_swap(pocket, 1);
			ft_revrotate(pocket, 1);
		}
		else
		{
			ft_rotate(pocket, 1);
			ft_swap(pocket, 1);
			ft_revrotate(pocket, 1);
			ft_swap(pocket, 1);
		}

	}
}
*/