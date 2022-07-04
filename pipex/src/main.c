#include "../include/pipex.h"

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}



int main(int argc, char **argv, char **envp)
{
	t_cmdline	cmdline;
	pid_t		pid;
	int 		fd[2];
	int 		i;
	int status;
	char buff[4];

	i = 10;
	fd[0] = 100;
	fd[1] = 200;
	printf("main-start!\n");
	pipe(fd);
	printf("fork-start!\n");
	pid = fork();
	printf("pid : %d\n", pid);
	if (pid > 0)
	{
		int counter = 0;
		printf("부모프로세스!\n");
		wait(&status);
		read(fd[0], buff, 4);
		printf("buff %s\n", buff);
		printf("부모 fd : %d %d\n", fd[0], fd[1]);
		printf("status %d", status);
		while (counter < 3)
		{
			counter++;
			printf("                        부모프로세스%d\n", counter);
			sleep(1);
		}
		printf("pid : %d\n", pid);
	}
	else
	{
		int counter = 0;
		printf("자식프로세스!\n");
		printf("자식 fd : %d %d\n", fd[0], fd[1]);
		write(fd[1], "hi!\n", 4);
		while (counter < 10)
		{
			counter++;
			printf("자식프로세스%d\n", counter);
			sleep(1);
		}
	}
	// i = 0;
	// if (argc != 5)
	// 	return 0;
	// while (envp[i] != NULL)
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	// open_file(&cmdline, argc, argv, fd);
	// parsing_cmd(&cmdline, argc, argv, envp);
	printf("main- reutrn!\n");
	printf("pid : %d\n", pid);
	

	return 0;
}