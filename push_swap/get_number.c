#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

char	*total_str(char **argv, int argc)
{
	char	*new;
	char	*temp;
	int		i;

	i = 1;
	new = "";
	if (new == NULL)
		return (NULL);
	while (i < argc)
	{
		temp = ft_strjoin(new, " ");
		if (i != 1)
			free(new);
		new = temp;
		temp = ft_strjoin(new, argv[i]);
		free(new);
		new = temp;
		i++;
	}
	return (new);
}

int	check_num_repeat(t_deq *A)
{
	int		i;
	int		j;
	t_node	*ptr;
	t_node	*ptr2;

	ptr = A -> start;
	while (ptr != NULL)
	{
		ptr2 = ptr -> next;
		while (ptr2 != NULL)
		{
			if (ptr -> number == ptr2 -> number)
				return (-1);
			ptr2 = ptr2 -> next;
		}
		ptr = ptr -> next;
	}
	return (1);
}

void	free_getnumber(char **new)
{
	int	i;

	i = 0;
	while (new[i] != NULL)
	{
		free(new[i]);
		i++;
	}
	free(new);
}

int	get_number(char **argv, int argc, t_deq *A, char *str)
{
	char	**number_list;
	int		i;
	int		number;

	i = 0;
	number_list = ft_split(str, ' ');
	while (number_list[i] != NULL)
	{
		number = check_number(number_list[i]);
		if (number < 0)
		{
			free_getnumber(number_list);
			return (-1);
		}
		else
			push_back(A, new_node(number));
		i++;
	}
	free_getnumber(number_list);
	return (1);
}
