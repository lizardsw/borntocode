#ifndef PHILOSOPERS_H
# define PHILOSOPERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

enum	e_flag
{
	FAIL = 0,
	SUCCESS
};

enum	e_error
{
	NO_ERROR = 0,
	ARGC_ERROR,
	NULL_ERROR,
	DIGIT_ERROR,
	MUTEX_INIT_ERROR,
	THREAD_CREATE_ERROR,
	THREAD_JOIN_ERROR
};

typedef struct s_info
{
	int	philo_num;
	int	starve_time;
	int	eating_time;
	int	sleeping_time;
	int	full_num;
	long long start_time;
	pthread_mutex_t *fork;
}	t_info;

typedef struct s_philo
{
	pthread_t thread;
	t_info	*info;
	int philo_index;
	int	left_fork;
	int	right_fork;
	long long end_eat_time;
}	t_philo;

// philo_libft.c
int	ft_strlen(char	*str);
int	is_digit(char	*str);
int	ft_atoi(char *str);

// philo_init.c
int	init_info(int argc, char **argv, t_info *info);
int	init_philo(t_philo **philo, t_info *info);


// error.c
int ft_error(int errno);

void	show_info(t_info *info);

int	sit_philo_table(t_philo *philo, t_info *info);

long long get_time(void);
#endif