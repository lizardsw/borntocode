#include "push_swap.h"

void	rule_push_back(t_deq *deq, t_node *ptr, int i, int num)
{
	if (i <= 0)
	{
		push_back(deq, new_node(num));
		return ;
	}
	if (ptr -> number / 10 == num / 10)
	{
		if (ptr -> number % 10 == num % 10)
			push_back(deq, new_node(num));
		else if (ptr -> number % 10 != num % 10)
		{
			if ((ptr -> number % 10) != 3)
			{			
				delete_node(deq, ptr);
				push_back(deq, new_node((num / 10) * 10 + 3));
			}
			else
				rule_push_back(deq, ptr -> prev, --i, num);
		}
	}
	else
		push_back(deq, new_node(num));
	return ;
}

void	num_to_rule(int num)
{
	if (num == 1)
		ft_printf("sa\n");
	else if (num == 2)
		ft_printf("sb\n");
	else if (num == 3)
		ft_printf("ss\n");
	else if (num == 11)
		ft_printf("pa\n");
	else if (num == 12)
		ft_printf("pb\n");
	else if (num == 21)
		ft_printf("ra\n");
	else if (num == 22)
		ft_printf("rb\n");
	else if (num == 23)
		ft_printf("rr\n");
	else if (num == 31)
		ft_printf("rra\n");
	else if (num == 32)
		ft_printf("rrb\n");
	else if (num == 33)
		ft_printf("rrr\n");
}

void	rule_show_deq(t_deq *deq)
{
	t_node	*ptr;
	int		i;

	i = deq -> size;
	ptr = deq -> start;
	while (i > 0)
	{
		num_to_rule(ptr -> number);
		ptr = ptr -> next;
		i--;
	}
}
