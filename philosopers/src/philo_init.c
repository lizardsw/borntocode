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
	int errno;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->fork == NULL)
		return (NULL_ERROR);
	printf("%d\n", info->philo_num);
	i = 0;
	while (i < info->philo_num)
	{
		if(pthread_mutex_init(&(info->fork[i]), NULL))
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
		(*philo)[i].philo_index = i;
		i++;
	}
	return (NO_ERROR);
}

int	init_info(int argc, char **argv, t_info *info)
{
	int	errno;
	
	if (check_argv_digit(argv)) // 숫자 확인!
		return (DIGIT_ERROR);
	info->philo_num = ft_atoi(argv[1]);
	info->starve_time = ft_atoi(argv[2]);
	info->eating_time = ft_atoi(argv[3]);
	info->sleeping_time = ft_atoi(argv[4]);
	info->fork = NULL;
	if(pthread_mutex_init(&(info->print), NULL))
			return (MUTEX_INIT_ERROR);
	if (argc > 5)
		info->full_num = ft_atoi(argv[5]);
	else
		info->full_num = -1;
	return (init_fork(info));
}
