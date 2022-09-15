#include "philosopers.h"

void	philo_thinking(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	philo_printf(philo, info, FORK);
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	philo_printf(philo, info, FORK);
}

void	philo_eating(t_philo *philo, t_info *info)
{
	philo_printf(philo, info, EAT);
	usleep(info->eating_time);
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
}

void	philo_sleeping(t_philo *philo, t_info *info)
{
	philo_printf(philo, info, SLEEP);
	usleep(info->sleeping_time);
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		philo_thinking(philo, philo->info);
		philo_eating(philo, philo->info);
		philo_sleeping(philo, philo->info);
	}
	return (NULL);
}

int	sit_philo_table(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		philo[i].deadline = get_time(); + info->starve_time * 1000;
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		usleep(1);
		i++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		if(pthread_detach((philo[i].thread)))
			return (THREAD_JOIN_ERROR);
		i++;
	}
	return (NO_ERROR);
}