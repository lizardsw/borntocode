#include "../include/pipex.h"


int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int status;
	int fdk;
	int fdhi;
	pid_t pid;
	int i = 0;
	char	*a[3] = {"-c","1", NULL };
	char buff[5];
	buff[4] = '\0';
	fdk = open("../me.txt", O_RDONLY);
	fdhi = open("../hi.txt", O_WRONLY);
	char *cmd[3] = {"/bin/cat", "/bin/ls", NULL};
	
	
	pipe(fd);
	while (i < 2)
	{
		pid = fork();
		printf("%d %d %d\n", fdk, fd[0], fd[1]);
		if (pid > 0)
		{
			printf("부모\n");
			// write(fd[1], "1111", 5);
			wait(&status);
			// printf("부모 기다림끝\n");
			// dup2(fd[0], 0);
			// read(fd[0], buff, 4);
			// printf("%s\n",buff);
		}
		else
		{
			printf("자식\n");
			// read(fdk, buff, 4);
			// printf("buff %s\n", buff);
			// dup2(fdk, 0);
			printf("fdk :%d\n", fdk);
			printf("i :%d\n", i);
			// dup2(fdhi, 1);
			// execve("/bin/ls", a, envp);
			execve(cmd[i], 0, 0);
			return 0;
		}
		i++;
	}
}