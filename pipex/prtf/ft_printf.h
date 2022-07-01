/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@Student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:07:29 by seongwch          #+#    #+#             */
/*   Updated: 2022/01/22 18:07:31 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		check_size_pf(unsigned int num);
void	is_format(const char *str, va_list *ap, int *i, int *re);
void	print_c(va_list *ap, int *re);
void	print_d_i(va_list *ap, int *re);
void	print_s(va_list *ap, int *re);
void	print_p(va_list *ap, int *re);
char	*long_change_base(unsigned long long n, char *base);
char	*int_change_base(unsigned int n, char *base);
void	print_x(va_list *ap, int *re);
void	print_lx(va_list *ap, int *re);
void	print_u(va_list *ap, int *re);
char	*ft_uitoa(unsigned int num);
char	*zero_base(void);

#endif
