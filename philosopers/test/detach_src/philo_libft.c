#include "philosopers.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number);
}