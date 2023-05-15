#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[10000];
	srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = (rand() % 10000) - 5000;
    }
	int N = sizeof(arr) / sizeof(arr[0]);
	clock_t t = clock();
	quickSort(arr, 0, N - 1);
	t = clock() -t;
	double elapsed = (double) t/CLOCKS_PER_SEC;
	printf("CPU time: %.6f\n",elapsed);
	// printf("Sorted array: \n");
	// for (int i = 0; i < N; i++)
	// 	printf("%d ", arr[i]);
	return 0;
}
