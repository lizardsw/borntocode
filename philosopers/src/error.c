/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:17:16 by seongwch          #+#    #+#             */
/*   Updated: 2022/09/22 12:27:37 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

int	ft_error(int errno)
{
	if (errno == ARGC_ERROR)
		printf("argc_error!\n");
	else if (errno == NULL_ERROR)
		printf("malloc_error!\n");
	else if (errno == DIGIT_ERROR)
		printf("input error!\n");
	else if (errno == MUTEX_INIT_ERROR)
		printf("mutex_init_error!\n");
	else if (errno == THREAD_CREATE_ERROR)
		printf("thread_create_error!\n");
	else if (errno == THREAD_JOIN_ERROR)
		printf("thread_join_error!\n");
	return (1);
}
