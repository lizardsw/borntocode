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

enum	e_action
{
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DEAD
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
	int	total_must_eat;
	int simul;
	long long start_time;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
}	t_info;

typedef struct s_philo
{
	pthread_t thread;
	t_info	*info;
	int ph_index;
	int	left_fork;
	int	right_fork;
	int	must_eat;
	long long deadline;
	pthread_mutex_t die;
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
void	my_usleep(t_info *info, long long time);

long long	get_time(void);
long long	philo_printf(t_philo *philo, t_info *info, int flag);

#endif