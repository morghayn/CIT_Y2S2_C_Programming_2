#include "utility.h"

// Fisher–Yates shuffle algorithm
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Fisher–Yates shuffle algorithm
void shuffle_array(int arr[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}