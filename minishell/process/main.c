#include "process.h"




int	main()
{
	pid_t pid;
	int	pipe_fd;
	while (1)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("자식 프로제스\n");
		}
		else
		{
			wait(NULL);
			printf("부모 프로세스\n");
		}
	}




	return 0;
}