/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:23:31 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/22 18:23:32 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list *ap, int *re)
{
	unsigned long long	number;
	char				*str;
	char				*temp;

	number = va_arg(*ap, unsigned long long);
	str = long_change_base(number, "0123456789abcdef");
	if (str == NULL)
		return ;
	temp = ft_strjoin("0x", str);
	free(str);
	write(1, temp, ft_strlen(temp));
	(*re) = (*re) + ft_strlen(temp);
	free(temp);
}

void	print_x(va_list *ap, int *re)
{
	unsigned int		number;
	char				*str;

	number = va_arg(*ap, unsigned int);
	str = long_change_base(number, "0123456789abcdef");
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
	(*re) = (*re) + ft_strlen(str);
	free(str);
}

void	print_lx(va_list *ap, int *re)
{
	unsigned int		number;
	char				*str;

	number = va_arg(*ap, unsigned int);
	str = int_change_base(number, "0123456789ABCDEF");
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
	(*re) = (*re) + ft_strlen(str);
	free(str);
}
