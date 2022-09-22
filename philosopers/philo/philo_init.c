/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:15 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 20:56:02 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

static int	check_argv_digit(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_digit(argv[i]) == -1)
			return (DIGIT_ERROR);
		i++;
	}
	return (NO_ERROR);
}

static int	init_fork(t_info *info)
{
	int	i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* info->philo_num);
	if (info->fork == NULL)
		return (NULL_ERROR);
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL))
			return (MUTEX_INIT_ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	if (philo == NULL)
		return (NULL_ERROR);
	while (i < info->philo_num)
	{
		(*philo)[i].info = info;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % info->philo_num;
		(*philo)[i].ph_index = i;
		if (info->sh_total_must_eat >= 0)
			(*philo)[i].must_eat = info->sh_total_must_eat / info->philo_num;
		else
			(*philo)[i].must_eat = -1;
		if (pthread_mutex_init(&((*philo)[i].die), NULL))
			return (MUTEX_INIT_ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	init_info(int argc, char **argv, t_info *info)
{	
	if (check_argv_digit(argv))
		return (DIGIT_ERROR);
	info->philo_num = ft_atoi(argv[1]);
	info->starve_time = ft_atoi(argv[2]);
	info->eating_time = ft_atoi(argv[3]);
	info->sleeping_time = ft_atoi(argv[4]);
	if (info->philo_num < 0 || info->starve_time < 0 || \
			info->eating_time < 0 || info->sleeping_time < 0)
		return (DIGIT_ERROR);
	info->fork = NULL;
	if (pthread_mutex_init(&(info->print), NULL))
		return (MUTEX_INIT_ERROR);
	if (argc == 6)
		info->sh_total_must_eat = ft_atoi(argv[5]) * info->philo_num;
	else
		info->sh_total_must_eat = -1;
	if (info->philo_num == 0 || info->sh_total_must_eat == 0)
		return (DIGIT_ERROR);
	return (init_fork(info));
}