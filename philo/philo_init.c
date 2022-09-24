/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:52:16 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/24 15:38:31 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static t_error	init_info(t_info *info, int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_digit(argv[i]) == -1)
			return (DIGIT_ERROR);
		i++;
	}
	info->philo_num = ft_atoi(argv[1]);
	info->starve_tm = ft_atoi(argv[2]);
	info->eat_tm = ft_atoi(argv[3]);
	info->sleep_tm = ft_atoi(argv[4]);
	if (info->philo_num <= 0 || info->starve_tm < 0 || \
			info->eat_tm < 0 || info->sleep_tm < 0)
		return (DIGIT_ERROR);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (DIGIT_ERROR);
	}
	else
		info->must_eat = -1;
	return (NO_ERROR);
}

static t_error	init_fork(t_table *table, t_info info)
{
	int	i;

	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* info.philo_num);
	if (table->fork == NULL)
		return (NULL_ERROR);
	i = 0;
	while (i < info.philo_num)
	{
		if (pthread_mutex_init(&(table->fork[i]), NULL))
		{
			free(table->fork);
			return (MUTEX_INIT_ERROR);
		}
		i++;
	}
	return (NO_ERROR);
}

t_error	init_table(int argc, char **argv, t_table *table)
{
	t_error	errno;

	errno = init_info(&(table->info), argc, argv);
	if (errno != NO_ERROR)
		return (errno);
	table->sh_total_eat = table->info.philo_num * table->info.must_eat;
	if (pthread_mutex_init(&(table->print), NULL))
		return (MUTEX_INIT_ERROR);
	return (init_fork(table, table->info));
}

t_error	init_philo(t_philo **philo, t_table *table, t_info info)
{
	int	i;

	i = 0;
	(*philo) = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (philo == NULL)
		return (NULL_ERROR);
	while (i < info.philo_num)
	{
		(*philo)[i].table = table;
		(*philo)[i].fork[0] = i;
		(*philo)[i].fork[1] = (i + 1) % info.philo_num;
		(*philo)[i].index = i;
		(*philo)[i].must_eat = info.must_eat;
		i++;
	}
	return (NO_ERROR);
}
