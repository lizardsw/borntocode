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
		ft_printf("error!\n");
		//system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
		return (0);
	}
	sort_index_deq(a);
	atob(pocket, 1, a -> size);
	rule_show_deq(rule);
	
	//system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
