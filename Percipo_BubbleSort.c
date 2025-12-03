#include <stdio.h>
#include <stdbool.h>

/**
 * Swaps two integers
 * @param a: pointer to first integer
 * @param b: pointer to second integer
 */
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * BUBBLE SORT - LECTURE NOTES (OPTIMIZED VERSION)
 *
 * IDEA / INTUITION:
 * - Bubble sort repeatedly compares adjacent pairs of elements and swaps them
 *   if they are in the wrong order. Larger elements "bubble up" to the end of
 *   the array with each pass. It's simple but inefficient for large datasets.
 *
 * KEY INVARIANT:
 * - After i complete passes through the array, the last i elements are in
 *   their final sorted position (the i largest elements, properly placed).
 *   Each pass moves one more element to its correct position at the end.
 *
 * ALGORITHM (step-by-step):
 * 1. For i from 0 to n-2 (outer loop):
 *    a. Initialize swapped = false.
 *    b. For j from 0 to n-2-i (inner loop):
 *       - If arr[j] > arr[j+1], swap them and set swapped = true.
 *    c. If swapped == false, array is already sorted → break early.
 * 2. After all passes, the array is sorted.
 *
 * WHY OPTIMIZATION (swapped flag)?
 * - Naive bubble sort always does n-1 passes. This version detects if the
 *   array is already sorted and exits early, reducing unnecessary iterations.
 * - For a sorted array, it runs in O(n) instead of O(n²).
 *
 * WORKED EXAMPLE:
 * - Start: [64, 34, 25, 12, 22, 11, 90]
 *
 * Pass i=0 (swapped=true):
 *   Compare & swap: 64>34 [34,64,25,12,22,11,90]
 *                   64>25 [34,25,64,12,22,11,90]
 *                   64>12 [34,25,12,64,22,11,90]
 *                   64>22 [34,25,12,22,64,11,90]
 *                   64>11 [34,25,12,22,11,64,90]
 *                   64<90 [34,25,12,22,11,64,90]
 *   After pass: [34,25,12,22,11,64,90] (90 is now in place)
 *
 * Pass i=1 (swapped=true):
 *   After pass: [25,12,22,11,34,64,90] (64, 90 now in place)
 *
 * Pass i=2 (swapped=true):
 *   After pass: [12,22,11,25,34,64,90]
 *
 * Pass i=3 (swapped=true):
 *   After pass: [12,11,22,25,34,64,90]
 *
 * Pass i=4 (swapped=true):
 *   After pass: [11,12,22,25,34,64,90]
 *
 * Pass i=5 (swapped=false):
 *   No swaps occur → early exit
 *   Final: [11,12,22,25,34,64,90] ✓ SORTED
 *
 * COMPLEXITY:
 * - Best case: O(n) — array already sorted, 1 pass + 1 check pass
 * - Average case: O(n²) — random data
 * - Worst case: O(n²) — array sorted in reverse order
 * - Space: O(1) extra — sorts in-place
 *
 * CHARACTERISTICS / TIPS:
 * - Bubble sort is STABLE: equal elements maintain their relative order.
 * - Simple to understand and implement, making it good for teaching.
 * - Very poor for large datasets; use O(n log n) sorts like Quick Sort or
 *   Merge Sort in production.
 * - The inner loop limit decreases (j < n-1-i) because the last i elements
 *   are already in place, avoiding redundant comparisons.
 * - The swapped flag is key to the optimization; without it, worst-case
 *   performance remains O(n²) even for partially sorted arrays.
 *
 * COMPARISONS VS OTHER O(n²) SORTS:
 * - Selection Sort: fewer swaps, O(n) writes regardless; unstable
 * - Insertion Sort: O(n) best case; stable; better for small/nearly sorted data
 * - Bubble Sort: easy to understand; stable; simple early exit with flag
 *
 * @param arr: array to be sorted (modified in-place)
 * @param n: size of the array
 */
void bubbleSort(int arr[], int n)
{
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - 1; j++)
        {
            // Swap if current element is greater than next
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        // If no swapping happened, array is already sorted
        if (!swapped) break;
    }
}

/**
 * Prints array elements
 * @param arr: array to print
 * @param n: size of the array
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Main function to demonstrate bubble sort
 */
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Test with already sorted array
    int sortedArr[] = {1, 2, 3, 4, 5};
    int m = sizeof(sortedArr) / sizeof(sortedArr[0]);
    
    printf("\nAlready sorted array: ");
    printArray(sortedArr, m);
    
    bubbleSort(sortedArr, m);
    
    printf("After bubble sort: ");
    printArray(sortedArr, m);
    
    return 0;
}