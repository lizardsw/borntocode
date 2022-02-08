#include "ft_printf.h"
#include <stdio.h>


int hi(void)
{
    printf("hi\n");
    return (1);
}

int bye(void)
{
    printf("bye\n");
    return (1);
}

int main()
{
    char c = 'a';
    char *str;
    int d = 10;
    int i = -10u;

    str = NULL;
    if (hi() == 1 || bye() == -1)
        return (0);
    printf("end\n");
    return 0;
}