#include "push_swap.h"

void ft_sa(t_deq *A)
{
	t_node *ptr;
	t_node *temp;

	if (A -> size <= 2)
	{
		if (A -> size == 2)
		{
			push_back(A, pop_front(A));
		}
		return ;
	}
	ptr = A -> start -> next -> next;
	temp = A -> start -> next;
	ptr -> prev = A -> start;
	A -> start -> next = ptr;
	push_front(A, temp);
	A -> size--;
}

void ft_sb(t_deq *B)
{
	t_node *ptr;
	t_node *temp;

	if (B -> size <= 1)
	{
			return;
	}
	ptr = B -> start -> next -> next;
	temp = B -> start -> next;
	ptr -> prev = B -> start;
	B -> start -> next = ptr;
	push_front(B, temp);
	B -> size--;
};
void ft_ss(t_deq *A, t_deq *B)
{
	ft_sa(A);
	ft_sb(B);
};
void ft_pa(t_deq *A, t_deq *B)
{
	t_node *temp;
	
	temp = pop_front(B);
	if (temp != NULL)
		push_front(A, temp);
	
};
void ft_pb(t_deq *B, t_deq *A)
{
	t_node *temp;
	
	temp = pop_front(A);
	if (temp != NULL)
		push_front(B, temp);
};
void ft_rra(t_deq *A)
{
	if (A -> size > 1)
	{
		push_front(A, pop_back(A));
	}
};
void ft_rrb(t_deq *B)
{
	if (B -> size > 1)
	{
		push_front(B, pop_back(B));
	}
};
void ft_rrr(t_deq *A, t_deq *B)
{
	ft_ra(A);
	ft_rb(B);
};
void ft_ra(t_deq *A)
{
	if (A -> size > 1)
	{
		push_back(A, pop_front(A));
	}
};
void ft_rb(t_deq *B)
{
	if (B -> size > 1)
	{
		push_back(B, pop_front(B));
	}
};
void ft_rr(t_deq *A, t_deq *B)
{
	ft_rra(A);
	ft_rrb(B);
};