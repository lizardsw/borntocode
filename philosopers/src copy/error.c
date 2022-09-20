#include "philosopers.h"

int ft_error(int errno)
{
	if (errno == ARGC_ERROR)
		printf("argc_error!\n");
	else if (errno == NULL_ERROR)
		printf("malloc_error!\n");
	else if (errno == DIGIT_ERROR)
		printf("it is not digit!\n");
	else if (errno == MUTEX_INIT_ERROR)
		printf("mutex_init_error!\n");
	else if (errno == THREAD_CREATE_ERROR)
		printf("thread_create_error!\n");
	else if (errno == THREAD_JOIN_ERROR)
		printf("thread_join_error!\n");
	return (1);
}