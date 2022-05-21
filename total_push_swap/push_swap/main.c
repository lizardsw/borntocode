/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:18:28 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:30 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (get_number(a, str) == -1 || check_num_repeat(a) == -1)
	{
		ft_printf("Error!\n");
		exit (0);
	}
	if (sort_index_deq(a) == 1)
		atob(pocket, 1, a -> size);
	rule_show_deq(rule);
	return (0);
}
