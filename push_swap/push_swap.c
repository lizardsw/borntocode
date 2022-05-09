#include "push_swap.h"

int main(int argc, char **argv)
{
	t_deq *A;
	t_deq *B;
	t_deq *rule;
	t_pocket *pocket;
	char *str;

	A = new_deq();
	B = new_deq();
	rule = new_deq();
	pocket = new_pocket(A, B, rule);

	str = total_str(argv, argc);
	ft_printf("%s\n", str);
	if (get_number(argv, argc, A) == -1)
		return 0;
	show_deq(A);
	sort_index_deq(A);
	show_deq(A);
	show_deq(B);

	ft_printf("--------------------\n");
	AtoB(pocket, 1, A -> size);
	show_deq(A);
	show_deq(B);
/*
	pop_back(A);
	pop_front(A);
	show_deq(A);


	ft_pa(B,A);
	show_deq(A);
	show_deq(B);
	ft_ra(A);
	show_deq(A);
	ft_rra(A);
	show_deq(A);
*/
	return 0;
}