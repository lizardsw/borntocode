/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:11:25 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/22 18:11:26 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_format(const char *str, va_list *ap, int *i, int *re)
{
	(*i)++;
	if (str[*i] == 'c')
		print_c(ap, re);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_d_i(ap, re);
	else if (str[*i] == 's')
		print_s(ap, re);
	else if (str[*i] == 'p')
		print_p(ap, re);
	else if (str[*i] == 'u')
		print_u(ap, re);
	else if (str[*i] == 'x')
		print_x(ap, re);
	else if (str[*i] == 'X')
		print_lx(ap, re);
	else if (str[*i] == '%')
	{
		(*re)++;
		write(1, "%", 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		re;

	i = 0;
	re = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			is_format(str, &ap, &i, &re);
		else
		{
			re++;
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (re);
}
