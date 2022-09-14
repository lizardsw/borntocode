
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

pthread_mutex_t mutex;


void	*ft_thread(void *arg)
{
	int	i;
	char	**argv;
	i = 0;
	printf("hello!\n");
	argv = arg;
	while (1)
	{
		printf("waiting1....\n");
		pthread_mutex_lock(&mutex);
		while (argv[i] != NULL)
		{
			printf("thread 1 : %s\n", argv[i]);
			sleep(1);
			i++;
		}
		pthread_mutex_unlock(&mutex);
		i = 0;
		usleep(1);
	}
	printf("bye!\n");
	
	return NULL;
}

void	*ft_thread2(void *arg)
{
	int	i;
	char	**argv;
	i = 0;
	printf("hello2!\n");
	argv = arg;
	while (1)
	{
		printf("waiting2....\n");
		pthread_mutex_lock(&mutex);
		while (argv[i] != NULL)
		{
			printf("thread2 : %s\n", argv[i]);
			sleep(1);
			i++;
		}
		pthread_mutex_unlock(&mutex);
		i = 0;
		usleep(1);
	}
	printf("bye2!\n");
	return NULL;
}


int main()
{

	pthread_t t1;
	pthread_t t2;
	int	thread_id;
	int	i;

	pthread_mutex_init(&mutex, NULL);
	// init_info(argc, argv, &info);
	thread_id = pthread_create(&t2, NULL, ft_thread, argv);
	// printf("%d\n", thread_id);
	thread_id = pthread_create(&t1, NULL, ft_thread2, argv);
	// printf("%d\n", thread_id);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	// // pthread_detach(t1);
	// // if (argc == 5 || argc == 6)
	// // {
	// // 	if (parsing_argv(argc, argv, &int_argv) == -1)
	// // 		return (0);

	// // }
	// system("leaks a.out");



}