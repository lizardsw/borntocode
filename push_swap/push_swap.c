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
	//ft_printf("%s\n", str);
	if (get_number(argv, argc, A) == -1)
		return 0;
	//show_deq(A);
	sort_index_deq(A);
	//show_deq(A);
	//show_deq(B);
	
	//ft_printf("--------------------\n");
	AtoB(pocket, 1, A -> size);
	//show_deq(A);
	//show_deq(B);
	//show_deq(rule);

	rule_show_deq(rule);


	return 0;
}