#! /usr/bin/python3.10
from numpy import random
import time
def swap(A, i, j):
 
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
 
 
# Partition using the Lomuto partition scheme
def partition(a, start, end):
 
    # Pick the rightmost element as a pivot from the list
    pivot = a[end]
 
    # elements less than the pivot will be pushed to the left of `pIndex`
    # elements more than the pivot will be pushed to the right of `pIndex`
    # equal elements can go either way
    pIndex = start
 
    # each time we find an element less than or equal to the pivot,
    # `pIndex` is incremented, and that element would be placed
    # before the pivot.
    for i in range(start, end):
        if a[i] <= pivot:
            swap(a, i, pIndex)
            pIndex = pIndex + 1
 
    # swap `pIndex` with pivot
    swap(a, end, pIndex)
 
    # return `pIndex` (index of the pivot element)
    return pIndex
 
 
# Quicksort routine
def quicksort(a, start, end):
 
    # base condition
    if start >= end:
        return
 
    # rearrange elements across pivot
    pivot = partition(a, start, end)
 
    # recur on sublist containing elements less than the pivot
    quicksort(a, start, pivot - 1)
 
    # recur on sublist containing elements more than the pivot
    quicksort(a, pivot + 1, end)
 
 
# Python implementation of the Quicksort algorithm
a = random.randint(-5000, 5000, size=(10000))
t = time.process_time()
quicksort(a, 0, len(a) - 1)
t = time.process_time() - t
# print the sorted list
print("CPU time: ", t)