#include "../include/pipex.h"









int main(int argc, char **argv, char **envp)
{
	int pipefd[2];
	pid_t	pid;
	t_cmdline cmdline;

	cmdline.file1_fd = open("../hi.txt", O_RDWR);
	cmdline.file2_fd = open("../me.txt", O_WRONLY);

	char *cmd[3] = {"/bin/cat", "/bin/ls", NULL};
	int	i = 0;
	pid = fork();
	pipe(pipefd);
	if (pid == 0)
	{
		printf("자식\n");
		i++;
	}
	else
	{
		printf("부모\n");
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		printf("자식1\n");
		i++;
	}
	else
	{
		printf("부모1\n");
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		printf("자식2\n");
		//i++;
		
	}
	else
	{
		printf("부모2\n");
		i++;
	}
	printf("i:%d\n", i);
	printf("return!\n");
	return 0;
}