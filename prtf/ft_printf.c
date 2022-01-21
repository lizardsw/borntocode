#include "ft_printf.h"

void is_format(const char* str, va_list* ap, int *i)
{
	(*i)++;
	if (str[*i] == 'c')
		print_c(ap);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_d_i(ap);
	else if (str[*i] == 's')
		print_s(ap);
	else if (str[*i] == 'p')
		print_p(ap);
	else if (str[*i] == 'u')
		print_u(ap);
	else if (str[*i] == 'x')
		print_x(ap);
	else if (str[*i] == 'X')
		print_X(ap);
	else if (str[*i] == '%')
		write(1,"%",1);
}

int ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			is_format(str, &ap, &i);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return 0;
}