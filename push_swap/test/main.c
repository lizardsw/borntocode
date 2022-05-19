#include "test.h"

int main()
{
	printf("hi!\n");
	int arr[10] = {10,1,3,4,6,2,5,7,8,9};

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	quick(arr, 0, 9);
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

}