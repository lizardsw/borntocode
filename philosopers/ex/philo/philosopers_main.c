/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:34:19 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/23 15:38:22 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

int	check_dead(t_philo *philo, t_info *info)
{
	long long	now;

	now = (get_time());
	if (now - philo->sh_deadline >= 0)
	{
		pthread_mutex_lock(&(info->print));
		if (info->sh_simul == 1)
			printf("%lld %d %s\n", (now - info->start_time) / 1000, \
						philo->ph_index + 1, "died");
		info->sh_simul = 0;
		pthread_mutex_unlock(&(info->print));
		pthread_mutex_unlock(&(philo->die));
		return (FAIL);
	}
	pthread_mutex_unlock(&(philo->die));
	return (SUCCESS);
}

void	monitor_philo(t_philo *philo, t_info *info)
{
	int	i;
	int	flag;

	flag = SUCCESS;
	while (flag == SUCCESS)
	{
		i = info->philo_num - 1;
		while (i >= 0 && flag == SUCCESS)
		{
			flag = check_dead(&philo[i], info);
			i--;
		}
		// usleep(50);
	}
	i = 0;
	if (info->philo_num == 1)
	{
		pthread_detach(philo[i].thread);
		return ;
	}
	while (i < info->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	int		errno;

	if (argc != 5 && argc != 6)
		return (ft_error(ARGC_ERROR));
	errno = init_info(argc, argv, &info);
	if (errno)
		return (ft_error(errno));
	errno = init_philo(&philo, &info);
	if (errno)
		return (ft_error(errno));
	sit_philo_table(philo, &info);
	monitor_philo(philo, &info);
	return (0);
}
