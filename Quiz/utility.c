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
	srand((unsigned int) time(NULL));

	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}


// Fisher–Yates shuffle algorithm
void swap_char_pointer(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

// Fisher–Yates shuffle algorithm
void shuffle_char_array(char arr[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		//printf("i: %d\tj%d", i, j);
		swap_char_pointer(&arr[i], &arr[j]);
	}
}

int random(int lower, int upper)
{
	// srand((unsigned int) time(NULL));
	srand(rand());
	return (rand() % (upper - lower + 1)) + lower;
}