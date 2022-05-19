#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deq		*a;
	t_deq		*b;
	t_deq		*rule;
	t_pocket	*pocket;
	char		*str;

	a = new_deq();
	b = new_deq();
	rule = new_deq();
	pocket = new_pocket(a, b, rule);
	str = total_str(argv, argc);
	if (get_number(argv, argc, a, str) == -1 || check_num_repeat(a) == -1)
	{
		ft_printf("error!\n");
		return (0);
	}
	sort_index_deq(a);
	atob(pocket, 1, a -> size);
	rule_show_deq(rule);
	return (0);
}
