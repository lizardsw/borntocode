#include "push_swap.h"

void	atob_small_sort(t_pocket *pocket, int start, int end)
{
	int	range;

	range = end - start + 1;
	if (range == 2)
	{	
		if (pocket -> A -> start -> index == end)
			ft_swap(pocket, 1);
	}
}

void	btoa_small_sort(t_pocket *pocket, int start, int end)
{
	int	range;

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
