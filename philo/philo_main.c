/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:48:47 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/24 15:40:31 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

void	sss()
{
	system("leaks philo");
}

static t_flag	check_dead(t_philo *philo, t_table *table)
{
	long long	now;
	int			i;

	
	i = 0;
	if (table->sh_total_eat == 0)
	{
		table->sh_simul = 0;
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	while (i < table->info.philo_num)
	{
		now = get_time_from(table->sh_start_time);
		if (now - philo[i].sh_dead_tm >= 0)
		{
			if (table->sh_simul == 1)
				printf("%lld %d %s\n", now, philo[i].index + 1, "died");
			table->sh_simul = 0;
			pthread_mutex_unlock(&(table->print));
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

static void	monitor_philo(t_philo *philo, t_table *table)
{
	int		i;
	t_flag	flag;

	flag = SUCCESS;
	i = 0;
	while (flag == SUCCESS)
	{
		usleep(10);
		pthread_mutex_lock(&(table->print));
		flag = check_dead(philo, table);
		pthread_mutex_unlock(&(table->print));
	}
	if (table->info.philo_num == 1)
	{
		pthread_detach(philo[i].thread);
		return ;
	}
	while (i < table->info.philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;
	t_philo	*philo;
	t_error	errno;
	
	atexit(sss);
	if (argc != 5 && argc != 6)
		return (ft_error(ARGC_ERROR));
	errno = init_table(argc, argv, &table);
	if (errno)
		return (ft_error(errno));
	errno = init_philo(&philo, &table, table.info);
	if (errno)
		return (ft_error(errno));
	errno = sit_philo_table(philo, &table, table.info);
	if (errno)
		return (ft_error(errno));
	monitor_philo(philo, &table);
	free(philo);
	table_free(&table);
	return (0);
}
