#include <stdio.h>
#include <unistd.h>

int main()
{
    int k = 4;
    int *pt = &k;
    long long me = (long long)&k;

    printf("%lld\n", me);
    printf("%lu\n", sizeof(pt));
    printf("%lu\n %lu", sizeof(int), sizeof(me));


    return 0;
}