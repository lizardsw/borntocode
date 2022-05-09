#include "push_swap.h"

void ft_swap(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_sa(pocket -> A);
	else if (num == 2)
		ft_sb(pocket -> B);
	push_back(pocket -> rule, new_node(num));
}

void ft_push(t_pocket *pocket, int num)
{
	if(num == 1)
		ft_pa(pocket -> A, pocket -> B);
	else
		ft_pa(pocket -> B, pocket -> A);
	push_back(pocket -> rule, new_node(num + 10));
}

void ft_rotate(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_ra(pocket -> A);
	else if (num == 2)
		ft_rb(pocket -> B);
	push_back(pocket -> rule, new_node(num + 20));
}

void ft_revrotate(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_rra(pocket -> A);
	else if (num == 2)
		ft_rrb(pocket -> B);
	push_back(pocket -> rule, new_node(num + 20));
}