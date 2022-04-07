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

int	get_number(char **argv, int argc, t_deq *A)
{
	char	**number_list;
	int		i;
	int		number;

	i = 0;
	number_list = ft_split(total_str(argv, argc), ' ');
	while (number_list[i] != NULL)
	{
		number = check_number(number_list[i]);
		if (number < 0)
		{
			ft_printf("error!\n");
			return (-1);
		}
		else
			push_back(A, new_node(number));
		i++;
	}
	if (check_num_repeat(A) == -1)
	{
		ft_printf("error!\n");
		return (-1);
	}
	return (1);
}
