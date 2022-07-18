#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

enum token
{
	CHAR = 0,
	SPACES = 1,
	REDIR = 2,
	PIPE = 3,
	QUOTE = 4,
	ZERO = 5
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
} t_list;

void	show_list(t_list *list);
t_list *new_list(void);
t_node *new_node(char *str);
void	push_node_back(t_list *list, t_node *node);
void	push_node_front(t_list *list, t_node *node);
t_node *pop_node_back(t_list *list);
t_node *pop_node_front(t_list *list);


t_list *shell_split(char *str);


#endif