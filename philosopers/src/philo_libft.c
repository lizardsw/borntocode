/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:17:23 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/21 21:36:09 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

int	is_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number);
}