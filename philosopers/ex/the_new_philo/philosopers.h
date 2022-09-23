/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:40:53 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/23 19:21:57 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPERS_H
# define PHILOSOPERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum	e_flag
{
	FAIL = 0,
	SUCCESS
}	e_flag;

typedef enum	e_error
{
	NO_ERROR = 0,
	ARGC_ERROR,
	NULL_ERROR,
	DIGIT_ERROR,
	MUTEX_INIT_ERROR,
	THREAD_CREATE_ERROR,
	THREAD_JOIN_ERROR
} e_error;

typedef struct info
{
	int			philo_num;
	int			sleep_tm;
	int			eat_tm;
	int			starve_tm;
	int			must_eat;
}	t_info;

typedef struct s_table
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_info			info;
	int				sh_simul;
	int				sh_total_eat;
	struct timeval	sh_start_time;
}	t_table;

// 0 left_fork 1 right_fork
typedef struct s_philo
{
	pthread_t	thread;
	t_info		info;
	t_table		*table;
	int			index;
	int			fork[2];
	int			must_eat;
	long long	sh_dead_tm;
}	t_philo;

int			is_digit(char	*str);
int			ft_atoi(char *str);

e_error	init_table(int argc, char **argv, t_table *table);
e_error	init_philo(t_philo **philo, t_table *table, t_info info);

int	ft_error(int errno);

long long	get_time_from(struct timeval start_time);
long long	start_time(void);
void	my_usleep(long long time, struct timeval start_time);
void	*philo_action(void *data);
e_error	sit_philo_table(t_philo *philo, t_table *table, t_info info);



#endif