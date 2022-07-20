#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "list.h"

// gcc -lreadline -L ~/goinfre/.brew/opt/readline/lib -I ~/goinfre/.brew/opt/readline/include readline.c
// 위에 명령어를 통해 함수를 사용할 수 있다!!
void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
	{
		printf("rl_one_new_line = -1!\n");
		exit(1);
	}
	rl_replace_line("", 1);
	rl_redisplay();
}

int		main(void)
{
	int				ret;
	char			*line;
	t_list			*list;
	t_process		**storage;

	signal(SIGINT, handler);
	while (true)
	{
		line = readline("input> ");
		if (line)
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			add_history(line);
			list = shell_split(line);
			show_list(list);
			if (list->state == GOOD)
			{
				storage = cmd_storage(list);
				show_process(storage);
				if (syntax_error(storage) == -1)
				{
					printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
					printf("$$$$$$$syntax_error!$$$$$$$$$$\n");
					printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				}
				free_process(storage);
			}
			else if(list->state == ERROR)
			{
				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
				printf("@@@@@@@@@@ QUOTE error!@@@@@@@@@@\n");
				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

			}
			free_list(list);
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return (1);
	}
	return (0);
}