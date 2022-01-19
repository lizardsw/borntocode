#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft2/libft.h"

int ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	char	c;
	char	*hi;
	int		num;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
				i++;
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				num = va_arg(ap, int);
				hi = ft_itoa(num);
				write(1, hi, ft_strlen(hi));
				free(hi);
				i++;
			}

		}
		else
			write(1, &str[i], 1);
		i++;
	}

	return 0;
}


int main()
{
	char	a = 'a';
	char	b = 'b';
	char	c = 'c';
	char	*name = "123";
	int		num = 100;


	ft_printf("hi! a:%c b:%c c:%c number:%d", a, b, c, num);
	printf("\n");
	printf("%zu", ft_strlen(name));
	return 0;
}