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

#define N 10000
int binarySearch(int nums[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
 
int main(void)
{
    int nums[N];
	srand(time(NULL));
    for (int i = 0; i < N; i++) {
        nums[i] = (rand() % N) - N/2;
    }
    quickSort(nums, 0, N -1);
    int target = (rand() % N) - N/2;
 
    int n = sizeof(nums)/sizeof(nums[0]);
    clock_t t = clock();
    int index = binarySearch(nums, n, target);
    t = clock() - t;
    double elapsed = (double) t/CLOCKS_PER_SEC;
    printf("CPU time: %.6f\n",elapsed);
 
    if (index != -1) {
        printf("Element found at index %d\n", index);
    }
    else {
        printf("Element not found in the array\n");
    }
 
    return 0;
}