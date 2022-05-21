/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:23:23 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/22 18:23:24 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list *ap, int *re)
{
	char	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	(*re)++;
}

void	print_d_i(va_list *ap, int *re)
{
	int		num;
	char	*str;

	num = va_arg(*ap, int);
	str = ft_itoa(num);
	write(1, str, ft_strlen(str));
	(*re) = (*re) + ft_strlen(str);
	free(str);
}

void	print_s(va_list *ap, int *re)
{
	char	*str;
	int		check;

	check = 0;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		check = 1;
	}
	(*re) += write(1, str, ft_strlen(str));
	if (check == 1)
		free(str);
}

void	print_u(va_list *ap, int *re)
{
	unsigned int	num;
	char			*str;

	num = va_arg(*ap, unsigned int);
	str = ft_uitoa(num);
	write(1, str, ft_strlen(str));
	(*re) = (*re) + ft_strlen(str);
	free(str);
}
