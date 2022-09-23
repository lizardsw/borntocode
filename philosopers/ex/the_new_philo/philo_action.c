/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:48:47 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/23 22:31:32 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static e_flag pick_up(t_philo *philo, t_table *table)
{
	long long	now;

	pthread_mutex_lock(&(table->fork[philo->fork[philo->index % 2]]));
	pthread_mutex_lock(&(table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	printf("%lld %d %s\n", now / 1000, philo->index + 1, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
	pthread_mutex_lock(&(table->fork[philo->fork[!(philo->index % 2)]]));
	pthread_mutex_lock(&(table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	printf("%lld %d %s\n", now / 1000, philo->index + 1, "has taken a fork");
	pthread_mutex_unlock(&(table->print));
	return (SUCCESS);
}

static e_flag eating(t_philo *philo, t_table *table, t_info info)
{
	long long	now;
	
	if (pick_up(philo, table) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&(table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	// if (now -  philo->sh_dead_tm >= 0)
	// {
	// 	table->sh_simul = 0;
	// 	pthread_mutex_unlock(&(table->print));
	// 	return (FAIL);
	// }
	philo->sh_dead_tm = now + info.starve_tm * 1000;
	printf("%lld %d %s\n", now / 1000, philo->index + 1, "is eating");
	pthread_mutex_unlock(&(table->print));

	
	my_usleep(info.eat_tm * 1000, table->sh_start_time);
	pthread_mutex_unlock(&(table->fork[philo->fork[0]]));
	pthread_mutex_unlock(&(table->fork[philo->fork[1]]));
	philo->must_eat--;
	return (SUCCESS);
}

static e_flag sleeping(t_philo *philo, t_table *table, t_info info)
{
	long long	now;
	
	pthread_mutex_lock(&(table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	printf("%lld %d %s\n", now / 1000, philo->index + 1, "is sleeping");
	pthread_mutex_unlock(&(table->print));
	my_usleep(info.sleep_tm * 1000, table->sh_start_time);
	return (SUCCESS);
}

static e_flag thinking(t_philo *philo, t_table *table, t_info info)
{
	long long	now;
	
	pthread_mutex_lock(&(philo->table->print));
	if (table->sh_simul == 0)
	{
		pthread_mutex_unlock(&(table->print));
		return (FAIL);
	}
	now = get_time_from(table->sh_start_time);
	printf("%lld %d %s\n", now / 1000, philo->index + 1, "is thinking");
	pthread_mutex_unlock(&(philo->table->print));
	if (info.eat_tm > info.sleep_tm)
		my_usleep((info.eat_tm - info.sleep_tm) * 1000, table->sh_start_time);
	if (info.philo_num % 2 == 1)
		usleep(300);
	return (SUCCESS);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// printf("--philo %d--\n", philo->index);
	while (philo->must_eat != 0)
	{
		if (eating(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
		if (philo->must_eat == 0)
			return (NULL);
		if (sleeping(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
		if (thinking(philo, philo->table, philo->table->info) == FAIL)
			return (NULL);
	}
	return (NULL);
}


