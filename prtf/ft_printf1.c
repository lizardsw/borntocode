#include "ft_printf.h"

void print_c(va_list *ap)
{
    char c;

    c = va_arg(*ap, int);
    write(1, &c, 1);
}

void print_d_i(va_list *ap)
{
    int num;
    char    *str;
     
    num = va_arg(*ap, int);
    str = ft_itoa(num);
    write(1, str, ft_strlen(str));
    free(str);
}

void print_s(va_list *ap)
{
    char    *str;

    str = va_arg(*ap, char *);
    write(1, str, ft_strlen(str));
}

void print_u(va_list *ap)
{
    unsigned int num;
    char *str;

    num = va_arg(*ap, unsigned int);
    str = ft_uitoa(num);
    write(1, str, ft_strlen(str));
    free(str);
}