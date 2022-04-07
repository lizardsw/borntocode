#include "push_swap.h"



int main(int argc, char **argv)
{
	t_deq *A;
	t_deq *B;
	char *str;

	A = new_deq();
	B = new_deq();
	str = total_str(argv, argc);
	ft_printf("%s\n", str);
	if (get_number(argv, argc, A) == -1)
		return 0;
	show_deq(A);
	return 0;
}