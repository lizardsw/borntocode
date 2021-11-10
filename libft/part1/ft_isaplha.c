#include"libft.h"

int	ft_isaplha(char c)
{
	if (c>= 'a' && c<= 'z')
		return 1;
	else if (c>= 'A' && c<= 'Z')
		return 2;
	else
		return 0;
}	
