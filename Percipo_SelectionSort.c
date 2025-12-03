#include <stdio.h>

/**
 * Swaps two integers
 * @param a: pointer to first integer
 * @param b: pointer to second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * SELECTION SORT - LECTURE NOTES
 *
 * IDEA / INTUITION:
 * - Selection sort repeatedly selects the smallest (or largest) element from
 *   the unsorted portion and moves it to the end of the sorted portion.
 *   Think of it as building the sorted prefix one element at a time.
 *
 * KEY INVARIANT:
 * - At the start of each outer-loop iteration `i`, the subarray arr[0..i-1]
 *   contains the i smallest elements in sorted order. The remaining elements
 *   arr[i..n-1] are unsorted and contain the rest.
 *
 * ALGORITHM (step-by-step):
 * 1. For i from 0 to n-2:
 *    a. Find the index `minIndex` of the minimum element in arr[i..n-1].
 *    b. Swap arr[i] with arr[minIndex] (if minIndex != i).
 * 2. After the loop, the array is sorted in ascending order.
 *
 * WORKED EXAMPLE:
 * - Start: [64, 25, 12, 22, 11]
 *   i=0: find min in [64,25,12,22,11] => 11 (idx 4) -> swap -> [11,25,12,22,64]
 *   i=1: find min in [25,12,22,64] => 12 (idx 2) -> swap -> [11,12,25,22,64]
 *   i=2: find min in [25,22,64] => 22 (idx 3) -> swap -> [11,12,22,25,64]
 *   i=3: find min in [25,64] => 25 (idx 3) -> swap -> [11,12,22,25,64]
 *
 * COMPLEXITY:
 * - Time: O(n^2) comparisons in all cases (nested loops). Swaps: O(n) in
 *   the worst case (one per outer iteration).
 * - Space: O(1) extra — sorts in-place.
 *
 * CHARACTERISTICS / TIPS:
 * - Selection sort is NOT stable by default: equal elements may change order
 *   after swaps. A stable variant requires extra work.
 * - It performs fewer writes than some other O(n^2) sorts (useful when
 *   writes are expensive, e.g., EEPROM/flash programming).
 * - Good for small arrays or when memory is constrained; otherwise use
 *   O(n log n) algorithms for large n.
 *
 * @param arr: array to be sorted (modified in-place)
 * @param n: size of the array
 */
void selectionSort(int arr[], int n)
{
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        if (minIndex != i) swap(&arr[i], &arr[minIndex]);
    }
}

/**
 * Prints array elements
 * @param arr: array to print
 * @param n: size of the array
 */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Main function to demonstrate selection sort
 */
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}