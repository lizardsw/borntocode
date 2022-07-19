#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

enum group
{
	WORD = 0,
	SPACES = 1,
	REDIR = 2,
	PIP = 3,
	QUOTE = 4,
	ZERO = 5
};

enum token
{
	CMD = 0,
	RDIN = 1,
	RDOUT = 2,
	RDRDIN = 3,
	RDRDOUT = 4,
	PIPE = 5,
	SCOLON = 6
};

typedef struct s_node
{
	struct s_node *prev;
	struct s_node *next;
	char	*data;
	int		token;
}	t_node;

typedef struct s_list
{
	t_node *start;
	t_node *end;
	int	number;
	int pipe_num;
}	t_list;

typedef struct s_process
{
	t_list	*redir;
	t_list	*cmd;
	int		token;
} t_process;

void	show_list(t_list *list);
t_list *new_list(void);
t_node *new_node(char *str, int token);
void	push_node_back(t_list *list, t_node *node);
void	push_node_front(t_list *list, t_node *node);
t_node *pop_node_back(t_list *list);
t_node *pop_node_front(t_list *list);


t_list *shell_split(char *str);
t_process **cmd_storage(t_list *list);
void	show_process(t_process **ptr);


void	free_node(t_node *ptr);
void	free_list(t_list *list);
void	free_process(t_process **prc);


#endif