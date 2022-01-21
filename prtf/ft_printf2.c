#include "ft_printf.h"

void print_p(va_list *ap)
{
    long long number;
    char    *str;
    char    *temp;

    number = va_arg(*ap, long long);
    str = change_base(number, "0123456789abcdef");
    if (str == NULL)
        return ;
    temp = ft_strjoin("0x", str);
    free(str);
    write(1, temp, ft_strlen(temp));
    free(temp);
}

void print_x(va_list *ap)
{
    int number;
    char    *str;

    number = va_arg(*ap, int);
    str = change_base(number, "0123456789abcdef");
    if (str == NULL)
        return ;
    write(1, str, ft_strlen(str));
    free(str);
}

void print_X(va_list *ap)
{
    int     number;
    char    *str;

    number = va_arg(*ap, int);
    str = change_base(number, "0123456789ABCDEF");
    if (str == NULL)
        return ;
    write(1, str, ft_strlen(str));
    free(str);
}
