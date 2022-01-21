#ifndef FT_PRINTF_H 
 #define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int     ft_printf(const char *str, ...);
void    print_c(va_list *ap);
void    print_d_i(va_list *ap);
void    print_s(va_list *ap);
void    print_p(va_list *ap);
char    *change_base(long long n, char *base);
void    print_x(va_list *ap);
void    print_X(va_list *ap);
void    print_u(va_list *ap);
char    *ft_uitoa(unsigned int num);

#endif