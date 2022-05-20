/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:18:48 by seongwch          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:55 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int		i;
	int		sign;
	int		temp;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	temp = ft_atoi(str);
	if (i > 9 && (temp == 0 || temp == -1))
		return (-1);
	return (1);
}

char	*total_str(char **argv, int argc)
{
	char	*new;
	char	*temp;
	int		i;

	i = 1;
	new = "";
	while (i < argc)
	{
		temp = ft_strjoin(new, " ");
		if (i != 1)
			free(new);
		new = temp;
		temp = ft_strjoin(new, argv[i]);
		free(new);
		new = temp;
		i++;
	}
	return (new);
}

int	check_num_repeat(t_deq *A)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = A -> start;
	while (ptr != NULL)
	{
		ptr2 = ptr -> next;
		while (ptr2 != NULL)
		{
			if (ptr -> number == ptr2 -> number)
				return (-1);
			ptr2 = ptr2 -> next;
		}
		ptr = ptr -> next;
	}
	return (1);
}

void	free_getnumber(char **new_str)
{
	int	i;

	i = 0;
	while (new_str[i] != NULL)
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
}

int	get_number(t_deq *A, char *str)
{
	char	**number_list;
	int		i;
	int		check;

	i = 0;
	number_list = ft_split(str, ' ');
	while (number_list[i] != NULL)
	{
		check = check_number(number_list[i]);
		if (check < 0)
		{
			free_getnumber(number_list);
			return (-1);
		}
		else
			push_back(A, new_node(ft_atoi(number_list[i])));
		i++;
	}
	free_getnumber(number_list);
	return (1);
}
