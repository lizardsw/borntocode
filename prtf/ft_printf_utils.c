#include "ft_printf.h"

int check_size(unsigned int num)
{
    int size;

    size = 0;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        num = num / 10;
        size++;
    }
    return (size);
}

char *ft_uitoa(unsigned int num)
{
    int size;
    char * new;

    size = check_size(num);
    new = (char*)malloc(size * sizeof(char) + 1);
    if (new == NULL)
        return (NULL);
    new[size] = '\0';
    size--;
    while (size >= 0)
    {
        new[size] = num % 10 + '0';
        num = num / 10;
        size--;
    }    
    return (new);
}

char *change_base(long long n, char *base)
{
    char    *new;
    int num_size;
    long long temp;

    num_size = 0;
    temp = n;
    while (temp != 0)
    {
        temp = temp / 16;
        num_size++;
    }
    new = (char *)malloc(num_size * sizeof(char) + 1);
    if (new == NULL)
        return (NULL);
    new[num_size] = '\0';
    num_size = num_size - 1;
    while (n != 0)
    {
        new[num_size] = base[n % 16];
        num_size--;
        n = n / 16;
    }
    return (new);
}