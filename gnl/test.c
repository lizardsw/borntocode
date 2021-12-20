#include <stdio.h>
#include <stdlib.h>

int *test(void)
{
	static int *a;
	if (!a)
	{
		a =malloc(4);
		*a = 0;
	}
	a++;
	return a;
}

int main(void)
{
	printf("%d\n", *test());
	printf("%d\n", *test());
}

