#! /usr/bin/python3.10
from numpy import random
import time
def swap(A, i, j):
 
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
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
 
# Function to determine if a `target` exists in the sorted list `nums`
# or not using a binary search algorithm
def binarySearch(nums, target):
 
    # search space is nums[left…right]
    (left, right) = (0, len(nums) - 1)
 
    # loop till the search space is exhausted
    while left <= right:
 
        # find the mid-value in the search space and
        # compares it with the target
 
        mid = (left + right) // 2
 
        # overflow can happen. Use:
        # mid = left + (right - left) / 2
        # mid = right - (right - left) // 2
 
        # target is found
        if target == nums[mid]:
            return mid
 
        # discard all elements in the right search space,
        # including the middle element
        elif target < nums[mid]:
            right = mid - 1
 
        # discard all elements in the left search space,
        # including the middle element
        else:
            left = mid + 1
 
    # `target` doesn't exist in the list
    return -1
 
 
nums = random.randint(-5000, 5000, size=(10000))
target = random.randint(-5000, 5000)
quicksort(nums, 0, len(nums) -1)
t = time.process_time()
index = binarySearch(nums, target)
t = time.process_time() -t
print("CPU time:", t)
if index != -1:
    print('Element found at index', index)
else:
    print('Element found not in the list')