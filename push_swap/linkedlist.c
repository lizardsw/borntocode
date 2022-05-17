#include "push_swap.h"

t_pocket *new_pocket(t_deq *A, t_deq *B, t_deq *rule)
{
	t_pocket *new;

	new = (t_pocket *)malloc(sizeof(t_pocket));
	if (new == NULL)
		return (NULL);
	new -> A = A;
	new -> B = B;
	new -> rule = rule;
	return (new);
}

t_deq	*new_deq(void)
{
	t_deq	*new;

	new = (t_deq *)malloc(sizeof(t_deq));
	if (new == NULL)
		return (NULL);
	new -> start = NULL;
	new -> end = NULL;
	new -> size = 0;
	return (new);
}

t_node	*new_node(int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	new -> prev = NULL;
	new -> number = number;
	new -> index = 0;
	return (new);
}

void	push_front(t_deq *deq, t_node *node)
{
	if (deq -> size == 0)
	{
		deq -> start = node;
		deq -> end = node;
		deq -> size++;
		return ;
	}
	deq-> start -> prev = node;
	node -> next = deq -> start;
	deq -> start = node;
	deq -> size++;
}

void	push_back(t_deq *deq, t_node *node)
{
	if (deq -> size == 0)
	{
		deq -> start = node;
		deq -> end = node;
		deq -> size++;
		return ;
	}
	deq -> end -> next = node;
	node -> prev = deq -> end;
	deq -> end = node;
	deq -> end -> next = NULL;
	deq -> size++;
}

t_node	*pop_front(t_deq *deq)
{
	t_node	*temp;

	if (deq -> size == 0)
		return (NULL);
	if (deq -> size == 1)
	{
		temp = deq -> start;
		deq -> start = NULL;
		deq -> end = NULL;
		temp -> next = NULL;
		temp -> prev = NULL;
		deq -> size--;
		return (temp);
	}
	temp = deq -> start;
	deq -> start -> next -> prev = NULL;
	deq -> start = deq -> start -> next;
	temp -> next = NULL;
	temp -> prev = NULL;
	deq -> size--;
	return (temp);
}

t_node	*pop_back(t_deq *deq)
{
	t_node	*temp;

	if (deq -> size == 0)
			return (NULL);
	if (deq -> size == 1)
	{
		temp = deq -> end;
		deq -> end = NULL;
		deq -> start = NULL;
		deq -> size--;
		temp -> prev = NULL;
		temp -> next = NULL;
		return (temp);
	}
	temp = deq -> end;
	deq -> end -> prev -> next = NULL;
	deq -> end = deq -> end -> prev;
	temp -> prev = NULL;
	temp -> next = NULL;
	deq -> size--;
	return (temp);
}

void delete_node(t_deq *deq, t_node *pt)
{
	t_node *prev_pt;
	t_node *next_pt;
	
	prev_pt = pt -> prev;
	next_pt = pt -> next;
	if(pt -> next == NULL)
		free(pop_back(deq));
	else if (pt -> prev == NULL)
		free(pop_front(deq));
	else
	{
		prev_pt -> next = next_pt;	
		next_pt -> prev = prev_pt;
		pt -> next = NULL;
		pt -> prev = NULL;
		deq -> size--;
		free(pt);
	}
}

void rule_push_back(t_deq *deq, t_node *ptr, int i, int num)
{
	if (i <= 0)
	{
		push_back(deq, new_node(num));
		return;
	}
	if	(ptr -> number / 10 == num / 10)
	{
		if(ptr -> number % 10 == num % 10)
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
	return;
}

void num_to_rule(int num)
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
	int	i;

	i = deq -> size;
	ptr = deq -> start;
	while (i > 0)
	{
		num_to_rule(ptr -> number);
		ptr = ptr -> next;
		i--;
	}
}

void	show_deq(t_deq *deq)
{
	t_node	*ptr;
	int	i;

	i = deq -> size;
	ptr = deq -> end;
	ft_printf("end ");
	while (i > 0)
	{
		ft_printf("%d(%d) - ", ptr->number, ptr -> index);
		ptr = ptr -> prev;
		i--;
	}
	ft_printf("start TOP ");
	ft_printf("%d\n", deq -> size);
}

