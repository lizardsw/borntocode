#include "philosopers.h"


// 1. 철학자수
// 2. 먹지않으면 죽는 시간
// 3. 먹는시간
// 4. 자는 시간
// 5. 철학자들이 먹으면 종료되는 시간
void	show_info(t_info *info)
{
	int	i;

	i = 0;
	printf("philo_num :%d\n", (*info).philo_num);
	printf("starve_time :%d\n", (*info).starve_time);
	printf("eating_time :%d\n", (*info).eating_time);
	printf("sleeping_time :%d\n", (*info).sleeping_time);
	printf("full_num :%d\n", (*info).total_must_eat);
	// while (i < info->philo_num)
	// {
	// 	printf("philo : left -> %d right -> %d\n", info->philo[i].left_fork, info->philo[i].right_fork);
	// 	i++;
	// }
}

int		check_dead(t_philo *philo, t_info *info)
{
	long long	now;

	pthread_mutex_lock(&(philo->die));
	now = get_time();
	if (now - philo->deadline > 0)
	{
		pthread_mutex_lock(&(info->print));
		info->simul = 0;
		printf("%lld %d %s\n", (now - info->start_time) / 1000, philo->ph_index + 1, "died");
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
	int flag;

	flag = SUCCESS;
	while (flag == SUCCESS)
	{
		i = 0;
		while (i < info->philo_num && flag == SUCCESS)
		{
			flag = check_dead(&philo[i], info);
			i++;
			usleep(10);
		}
		my_usleep(info, 1000);
	}
	i = 0;
	while (i < info->philo_num)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_info	*info;
	t_philo *philo;
	int		errno;

	if (argc != 5 && argc != 6)
		return (ft_error(ARGC_ERROR));
	errno = init_info(argc, argv, &info);
	if (errno)
		return (ft_error(errno));
	show_info(info);
	errno = init_philo(&philo, info);
	if (errno)
		return (ft_error(errno));
	show_info(info);
	sit_philo_table(philo, info);
	monitor_philo(philo, info);
	return (0);
}