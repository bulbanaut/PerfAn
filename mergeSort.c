
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define N 10000

void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
 
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }
 
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}
 
void mergesort(int arr[], int aux[], int low, int high)
{
    if (high <= low) {
        return;
    }

    int mid = (low + ((high - low) >> 1));
 
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid + 1, high);
 
    Merge(arr, aux, low, mid, high);
}
 
int isSorted(int arr[])
{
    int prev = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (prev > arr[i])
        {
            printf("MergeSort Fails!!");
            return 0;
        }
        prev = arr[i];
    }
 
    return 1;
}
 
int main(void)
{
    int arr[N], aux[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 10000) - 5000;
    }
    clock_t t = clock();
    mergesort(arr, aux, 0, N - 1);
    t = clock() - t;
    double elapsed = (double) (t) / CLOCKS_PER_SEC;
    printf("CPU time: %.6f \n", elapsed);
    if (isSorted(arr))
    {   
        // for (int i = 0; i < N; i++) {
        //     printf("%d ", arr[i]);
        // }
    }
    return 0;
}