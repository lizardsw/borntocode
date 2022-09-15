#include "philosopers.h"

long long get_time(void)
{
	struct timeval	time;
	long long		micro_time;

	gettimeofday(&time, NULL);
	micro_time = time.tv_sec * 1000000 + time.tv_usec;
	return (micro_time);
}

static void	action_pf(long long time, int philo, char *str)
{
	printf("lldms %d %s\n", time / 1000, philo, str);
}

void	philo_printf(t_philo *philo, t_info *info, int flag)
{
	long long time_now;

	time_now = get_time();
	pthread_mutex_lock(&(info->print));
	if (info->simul == 1 && (info->full_num == -1 || philo->have_to_eat > 0)) // 실행 부분
	{
		if (flag == FORK)
			action_pf(time_now - info->start_time, philo->philo_index, "has taken a fork");
		else if (flag == EAT)
		{
			action_pf(info->start_time - time_now, philo->philo_index, "is eating");
			pthread_mutex_lock(&(philo->die));
			philo->deadline = info->start_time - time_now + info->start_time * 1000;
			philo->have_to_eat--;
			pthread_mutex_unlock(&(philo->die));
		}
		else if (flag == SLEEP)
			action_pf(info->start_time - time_now, philo->philo_index, "is sleeping");
		else if (flag == THINK)
			action_pf(info->start_time - time_now, philo->philo_index, "is thinking");
		else if (flag == DEAD)
			action_pf(info->start_time - time_now, philo->philo_index, "died");
	}
	pthread_mutex_unlock(&(info->print));
}

void	if_usleep(long long time)
{
	int	i;

	i = 0;
	while (i < time)
	{
		usleep(1000);
		i++;
	}
}
