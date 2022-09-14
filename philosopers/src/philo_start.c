#include "philosopers.h"


int	philo_thinking(t_philo *philo, t_info *info)
{
	long long current_time;

	current_time = get_time();
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	printf("philo%d : %lldms take left fork!\n", philo->philo_index, current_time);
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	printf("philo%d : %lldms take right fork!\n", philo->philo_index, current_time);
	return (SUCCESS);
}

int	philo_eating(t_philo *philo, t_info *info)
{
	// printf("philo%d : %lld\n", philo_index, info->philo[philo_index].end_eat_time);
	long long current_time;
	
	current_time = get_time();
	printf("philo%d : %lldms eating!\n", philo->philo_index, current_time);
	usleep(info->eating_time * 1000);
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	usleep(1);
	return 1;
}

int	philo_sleeping(t_philo *philo, t_info *info)
{
	long long current_time;

	current_time = get_time();
	printf("philo%d : %lldms sleeping!\n", philo->philo_index, current_time);
	usleep(info->sleeping_time * 1000);
	return 1;
}

void	*philo_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("---philo%d---\nleft %d right %d\n", philo->philo_index, philo->left_fork, philo->right_fork);
	while (1)
	{
		if (philo_thinking(philo, philo->info) == SUCCESS)		
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
		philo[i].end_eat_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, philo_action, (void *)&philo[i]))
			return (THREAD_CREATE_ERROR);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		if(pthread_join((philo[i].thread), NULL))
			return (THREAD_JOIN_ERROR);
		i++;
	}
	return (NO_ERROR);
}