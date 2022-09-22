/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:17:33 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 12:34:33 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPERS_H
# define PHILOSOPERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	int				philo_num;
	int				starve_time;
	int				eating_time;
	int				sleeping_time;
	int				total_must_eat;
	int				simul;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	t_info			*info;
	int				ph_index;
	int				left_fork;
	int				right_fork;
	int				must_eat;
	long long		deadline;
	pthread_mutex_t	die;
}	t_philo;

int			is_digit(char	*str);
int			ft_atoi(char *str);
int			init_info(int argc, char **argv, t_info *info);
int			init_philo(t_philo **philo, t_info *info);
int			ft_error(int errno);
void		*philo_action(void *data);
int			sit_philo_table(t_philo *philo, t_info *info);
void		my_usleep(long long time);
long long	get_time(void);
int			philo_printf(t_info *info, int index, char *str, int flag);

#endif
