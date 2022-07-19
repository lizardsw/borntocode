#include "list.h"


void	show_process(t_process **ptr)
{
	t_list	*redir;
	t_list	*cmd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i] != NULL)
	{
		j = 0;
		redir = ptr[i]->redir;
		cmd = ptr[i]->cmd;
		printf("-------------------\n");
		printf("process : token(%d)\n", ptr[i]->token);
		printf("redir\n");
		show_list(redir);
		printf("cmd\n");
		show_list(cmd);
		printf("-------------------\n");
		i++;
	}
}

t_process *new_process(void)
{
	t_process *new;

	new = (t_process *)malloc(sizeof(t_process));
	if (new == NULL)
		exit(1);
	new->redir = new_list();
	new->cmd = new_list();
	new->token = 0;
	return (new);
}

t_process **new_storage(int pipe_num)
{
	t_process **new;
	int			i;
	
	i = 0;
	new = (t_process **)malloc(sizeof(t_process *) * (pipe_num + 2));
	if (new == NULL)
		exit(1);
	while (i < pipe_num + 1)
	{
		new[i] = new_process();
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	label_token(t_node *ptr)
{
	char	*temp;

	temp = ptr->data;
	if (ptr->token == REDIR)
	{
		if (temp[0] == '<')
		{
			if(temp[1] == '<')
				ptr->token = RDRDIN;
			else
				ptr->token = RDIN;
		}
		else
		{
			if(temp[1] == '>')
				ptr->token = RDRDOUT;
			else
				ptr->token = RDOUT;
		}
	}
	else if (ptr->token == PIP)
	{
		if (temp[0] == '|')
			ptr->token = PIPE;
		else
			ptr->token = SCOLON;
	}
	else if (ptr->token == QUOTE)
		ptr->token = CMD;
}

void	mv_redir_syn(t_process *prc, t_list *split)
{
	t_node	*ptr;

	ptr = pop_node_front(split);
	label_token(ptr);
	push_node_back(prc->redir, ptr);
	if (split->start->token != PIP && split->start->token != REDIR)
	{
		ptr = pop_node_front(split);
		label_token(ptr);
		push_node_back(prc->redir, ptr);
	}
}

void	mv_cmd_syn(t_process *prc, t_list *split)
{
	t_node	*ptr;

	ptr = pop_node_front(split);
	label_token(ptr);
	push_node_back(prc->cmd, ptr);
}

void	mv_pip_syn(t_process *prc, t_list *split)
{
	t_node	*ptr;

	ptr = pop_node_front(split);
	if (ptr->data[0] == '|')
		prc->token = PIPE;
	else if (ptr->data[0] == ';')
		prc->token = SCOLON;
	free_node(ptr);
}

t_process **cmd_storage(t_list *list)
{
	t_process **storage;
	t_node		*ptr;
	int			i;

	i = 0;
	ptr = list->start;
	storage = new_storage(list->pipe_num);
	while (ptr != NULL)
	{
		if (ptr->token == REDIR)
			mv_redir_syn(storage[i], list);
		else if (ptr->token == WORD | ptr->token == QUOTE)
			mv_cmd_syn(storage[i], list);
		else if (ptr->token == PIP)
		{
			mv_pip_syn(storage[i], list);
			i++;
		}
		ptr = list->start;
	}
	return storage;
}
