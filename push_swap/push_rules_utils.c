#include "push_swap.h"

void ft_swap(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_sa(pocket -> A);
	else if (num == 2)
		ft_sa(pocket -> B);
	push_back(pocket -> rule, new_node(num));
	//rule_push_back(pocket -> rule, pocket -> rule -> end, pocket -> rule -> size, num);
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
	//rule_push_back(pocket -> rule, pocket -> rule -> end, pocket -> rule -> size, num + 20);
}

void ft_revrotate(t_pocket *pocket, int num)
{
	if (num == 1)
		ft_rra(pocket -> A);
	else if (num == 2)
		ft_rrb(pocket -> B);
	push_back(pocket -> rule, new_node(num + 30));
	//rule_push_back(pocket -> rule, pocket -> rule -> end, pocket -> rule -> size, num + 30);
}

void rule_push_back(t_deq *deq, t_node *ptr, int i, int num)
{
	if (i == 0)
	{
		push_back(deq, new_node(num));
		return;
	}
	if	(ptr -> number / 10 == num / 10)
	{
		if(ptr -> number % 10 == num % 10)
			push_back(deq, new_node(num));
		else if (ptr -> number % 10 != num % 10 && ptr -> number != 3)
		{
			delete_node(deq, ptr);
			push_back(deq, new_node((num / 10) * 10 + 3));
		}
		else	
			rule_push_back(deq, ptr -> prev, i--, num);
	}
	else
	{
		push_back(deq, new_node(num));
	}
	return;
}




