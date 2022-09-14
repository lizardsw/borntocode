#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


long long get_time(void)
{
	struct timeval	time;
	long long		micro_time;

	gettimeofday(&time, NULL);
	micro_time = time.tv_sec * 1000000 + time.tv_usec;
	return (micro_time);
}


int main()
{
	struct timeval starttime;
	struct timeval endtime;
	long long start;
	long long end;

	gettimeofday(&starttime, NULL);
	start = get_time();
	usleep(1000000);
	gettimeofday(&endtime, NULL);
	end = get_time();


	printf("%ld\n", starttime.tv_sec);
	printf("%d\n\n", starttime.tv_usec);

	printf("%ld\n", endtime.tv_sec);
	printf("%d\n", endtime.tv_usec);
	printf("diff : %d\n", endtime.tv_usec - starttime.tv_usec);

	printf("%lld\n%lld\n%lld", start, end, end - start);

	return 0;
}