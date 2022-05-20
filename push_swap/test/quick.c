
#include <stdio.h>
#include "test.h"
#include "assert.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		if (sign * number > 2147483647)
		{
			return (-1);
		}
		else if (sign * number < -2147483648)
		{
			return (0);
		}
		i++;
	}
	return (sign * number);
}


void quick(int *arr, int start , int end)
{
	if(start >= end)
		return; 
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	assert(start != 0);

	while (i <= j)
	{
		while (arr[pivot] > arr[i] && i < end)
			i++;
		while (arr[pivot] < arr[j] && j > start)
			j--;

		if(i >= j)
			break;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	quick(arr, start, j - 1);
	quick(arr, j + 1, end);
}

int main(int argc, char **argv)
{
	 int temp;


	 temp = ft_atoi("-9999999999");
	printf("%d", temp);
	temp = atoi("-9999999999");
	printf("%d", temp);
	return 0;
}

void	show_deq(t_deq *deq)
{
	t_node	*ptr;
	int		i;

	i = deq -> size;
	ptr = deq -> end;
	ft_printf("end ");
	while (i > 0)
	{
		ft_printf("%d(%d) - ", ptr->number, ptr -> index);
		ptr = ptr -> prev;
		i--;
	}
	ft_printf("start TOP ");
	ft_printf("%d\n", deq -> size);
}