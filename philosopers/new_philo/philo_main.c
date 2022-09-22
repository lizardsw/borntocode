/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:48:47 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 21:42:30 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

int	main(int argc, char *argv[])
{
	t_table	table;
	t_philo	*philo;
	e_error errno;

	if (argc != 5 && argc != 6)
		return (ft_error(ARGC_ERROR));
	errno = init_table(argc, argv, &table);
	if (errno)
		return (ft_error(errno));
	errno = init_philo(&philo, &table, table.info);
	if (errno)
		return (ft_error(errno));

	return 0;
}