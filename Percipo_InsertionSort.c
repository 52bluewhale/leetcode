#include <stdio.h>

/**
 * INSERTION SORT - LECTURE NOTES
 *
 * IDEA / INTUITION:
 * - Build the sorted array one element at a time by taking the next element
 *   (the "key") and inserting it into its correct position among the
 *   previously sorted elements. Think of sorting a hand of playing cards.
 *
 * KEY INVARIANT:
 * - At the start of each outer-loop iteration `i`, the subarray arr[0..i-1]
 *   is sorted. The element arr[i] (the key) will be inserted into that sorted
 *   region so that arr[0..i] becomes sorted.
 *
 * ALGORITHM (step-by-step):
 * 1. For i from 1 to n-1:
 *    a. Store key = arr[i].
 *    b. Compare key with elements on its left (j = i-1, i-2, ...).
 *    c. Shift elements greater than key one position to the right to make
 *       room: arr[j+1] = arr[j].
 *    d. When the correct position is found (j < 0 or arr[j] <= key), place
 *       key at arr[j+1].
 * 2. Repeat until the entire array is sorted.
 *
 * WHY IT'S USEFUL:
 * - Very efficient for small or nearly sorted arrays (best case O(n)).
 * - Stable: equal elements keep their relative order.
 * - In-place: uses O(1) extra space.
 *
 * WORKED EXAMPLE:
 * - Start: [12, 11, 13, 5, 6]
 *   i=1: key=11, compare 12>11 → shift 12 → [12,12,13,5,6], insert 11 at pos0 → [11,12,13,5,6]
 *   i=2: key=13, 12<=13 → insert at pos2 → [11,12,13,5,6]
 *   i=3: key=5, shift 13,12,11 → [11,12,13,13,6] -> [11,12,12,13,6] -> [11,11,12,13,6], insert 5 → [5,11,12,13,6]
 *   i=4: key=6, shift 13,12,11 → insert 6 → [5,6,11,12,13] ✓
 *
 * COMPLEXITY:
 * - Best case: O(n) when the array is already sorted (no shifts needed).
 * - Average/Worst case: O(n^2) due to nested shifting for each insertion.
 * - Space: O(1) extra — sorts in-place.
 *
 * CHARACTERISTICS / TIPS:
 * - Stable sort: equal elements retain original order.
 * - Prefer insertion sort for small arrays or arrays that are mostly sorted.
 * - Minimizes the number of writes compared with some other O(n^2) sorts.
 * - Useful as the base case for recursive sorts (e.g., quicksort or mergesort)
 *   when subarrays become small.
 * - When implementing, be careful with the loop that shifts elements: ensure
 *   you stop when j < 0 or arr[j] <= key and then set arr[j+1] = key.
 *
 * VARIATIONS:
 * - Binary insertion sort: use binary search to find insertion point to reduce
 *   comparisons (still O(n^2) shifts).
 *
 * @param arr: array to be sorted (modified in-place)
 * @param n: size of the array
 */
void insertionSort(int arr[], int n)
{
    // Start from second element (first is already "sorted")
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        // to make space for key
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        // Insert key at its correct position
        arr[j+1] = key;
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
 * Main function to demonstrate insertion sort
 */
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Test with nearly sorted array
    int nearlySorted[] = {2, 3, 4, 5, 1};
    int m = sizeof(nearlySorted) / sizeof(nearlySorted[0]);
    
    printf("\nNearly sorted array: ");
    printArray(nearlySorted, m);
    
    insertionSort(nearlySorted, m);
    
    printf("After insertion sort: ");
    printArray(nearlySorted, m);
    
    return 0;
}