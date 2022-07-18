#include "list.h"


char	*get_strdup(char *src, int number)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * number + 1);
	if (new == NULL)
		exit(1);
	while (i < number)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	check_chr(char c)
{
	if (c == ' ')
		return (SPACES);
	else if (c == '<' || c == '>')
		return (REDIR);
	else if (c == '\'' || c == '\"')
		return (QUOTE);
	else if (c == '|' || c == ';')
		return (PIPE);
	else if (c == '\0')
		return (ZERO);
	return (CHAR);
}

int	push_token(t_list *list, char *str, int index, int len)
{
	char	*temp;

	temp = get_strdup(&str[index], len);
	push_node_back(list, new_node(temp));
	free(temp);
	return (len);
}

int	check_token(t_list *split_list, char *str)
{
	int		i;
	int		add_index;
	char	*temp;

	i = 0;
	add_index = 0;
	if (check_chr(str[0]) == PIPE)
		add_index = push_token(split_list, str, 0, 1);
	else if (check_chr(str[0]) == REDIR)
	{
		if (str[0] == str[1])
			add_index = push_token(split_list, str, 0, 2);
		else
			add_index = push_token(split_list, str, 0, 1);
	}
	else if (check_chr(str[0]) == QUOTE)
	{
		i = 1;
		while (str[0] != str[i] && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			exit(1);
		add_index = push_token(split_list, str, 1, i - 1) + 2;
	}
	else if (check_chr(str[0]) == SPACES)
	{
		while (str[i] == ' ')
			i++;
		add_index = i;
	}
	return (add_index);
}

t_list *shell_split(char *str)
{
	t_list	*split_list;
	char	*temp;
	int		token;
	int		i;
	int		j;

	i = 0;
	split_list = new_list();
	while (str[i] != '\0')
	{
		j = 0;
		while (!check_chr(str[i + j])) // 명령어 녀석들 아니면 세주는거야!! 쫄지마
			j++;
		if (j != 0)
			push_token(split_list, str, i, j);
		j += check_token(split_list, &str[i + j]);
		i = i + j;
	}
	return (split_list);
}