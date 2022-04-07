#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char c = 'a';
    char *str;
    int d = 10;
    int i = -10u;

    printf("%d", -10u);
    str = NULL;
    printf("no - %x", 3735929054u);
    //ft_printf("ft - %x\n", 3735929054u);
    return 0;
}