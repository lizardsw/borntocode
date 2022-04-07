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
   char *s = "abc%a\n";
   printf("%%%qaaa");
   
    return 0;
}