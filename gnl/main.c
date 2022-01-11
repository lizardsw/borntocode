#include "get_next_line.h"

# include <fcntl.h>
# include <stdio.h>

int main()
{
    int fd;
    int fd1;
    char    *str;
    int i = 0;

    printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
    fd = open("help.txt",O_RDONLY);
    fd1 = open("help2.txt",O_RDONLY);
    printf("fd : %d fd1 : %d\n", fd, fd1);
    while(i < 8)
    {
        str = get_next_line(fd);
        printf("*********fd - result********\n%s\n", str);
        str = get_next_line(fd1);
        printf("*********fd1 - result********\n%s\n", str);
        i++;
    }
    return 0;
}

//gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c