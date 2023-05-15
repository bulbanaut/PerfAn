// import java.util.Arrays;
 
class Quicksort
{
    public static void swap (int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
 
    // Partition using the Lomuto partition scheme
    public static int partition(int[] a, int start, int end)
    {
        // Pick the rightmost element as a pivot from the array
        int pivot = a[end];
 
        // elements less than the pivot will be pushed to the left of `pIndex`
        // elements more than the pivot will be pushed to the right of `pIndex`
        // equal elements can go either way
        int pIndex = start;
 
        // each time we find an element less than or equal to the pivot,
        // `pIndex` is incremented, and that element would be placed
        // before the pivot.
        for (int i = start; i < end; i++)
        {
            if (a[i] <= pivot)
            {
                swap(a, i, pIndex);
                pIndex++;
            }
        }
 
        // swap `pIndex` with pivot
        swap(a, end, pIndex);
 
        // return `pIndex` (index of the pivot element)
        return pIndex;
    }
 
    // Quicksort routine
    public static void quicksort(int[] a, int start, int end)
    {
        // base condition
        if (start >= end) {
            return;
        }
 
        // rearrange elements across pivot
        int pivot = partition(a, start, end);
 
        // recur on subarray containing elements less than the pivot
        quicksort(a, start, pivot - 1);
 
        // recur on subarray containing elements more than the pivot
        quicksort(a, pivot + 1, end);
    }
 
    // Java implementation of the Quicksort algorithm
    public static void main(String[] args)
    {
        int[] a = RandomUtils.randArray(1000, -5000, 5000);
 
        var t = System.nanoTime();
        quicksort(a, 0, a.length - 1);
        t = System.nanoTime() -t;
        double seconds = t * 0.00000001; 
        System.out.println("CPU time: " + seconds);
 
        // print the sorted array
        // System.out.println(Arrays.toString(a));
    }
}
