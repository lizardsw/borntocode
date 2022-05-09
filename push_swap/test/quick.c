#include <stdio.h>

void quick(int *arr, int start , int end)
{
	if(start >= end)
		return; 
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		while (arr[pivot] > arr[i] && i < end)
			i++;
		while (arr[pivot] < arr[j] && j > start)
			j--;

		if(i >= j)
			break;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	quick(arr, start, j - 1);
	quick(arr, j + 1, end);
}


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