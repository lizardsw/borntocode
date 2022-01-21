#include "ft_printf.h"

int main()
{
    char c = 'a';
    char *str = "seongwch";
    int i = 10;



    ft_printf("hi! my name is %c\nhi! str : %s\nmy age : %d\n pt : %p\n",c,str,i,&i);

    return 0;
}