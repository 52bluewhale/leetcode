#include <stdio.h>

// Swaps two elements in the array
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * PARTITION (LECTURE NOTES - Lomuto Scheme)
 *
 * IDEA / INTUITION:
 * - Partitioning is the key operation in quicksort. Choose a "pivot" element,
 *   then rearrange the array so that all elements <= pivot are to its left
 *   and all elements > pivot are to its right. The pivot ends up in its final
 *   sorted position. This divide-and-conquer step allows quicksort to work.
 *
 * KEY INVARIANT (Lomuto Scheme):
 * - At the start of each iteration of the main loop, the subarray arr[low..i]
 *   contains all elements seen so far that are <= pivot, and arr[i+1..j-1]
 *   contains elements that are > pivot. The unseen elements are arr[j..high-1],
 *   and arr[high] holds the pivot.
 *
 * ALGORITHM (step-by-step, Lomuto Scheme):
 * 1. Choose pivot = arr[high] (the rightmost element).
 * 2. Initialize i = low - 1 (marks boundary of "small" elements).
 * 3. For each j from low to high-1:
 *    a. If arr[j] <= pivot, increment i and swap arr[i] with arr[j].
 *       This moves arr[j] into the "small" region.
 * 4. After the loop, swap arr[i+1] with arr[high] to place pivot in its
 *    final position.
 * 5. Return i+1 (the pivot's final index).
 *
 * WHY IT WORKS:
 * - By maintaining the invariant, when the loop ends, everything left of i+1
 *   is <= pivot and everything right is > pivot. Swapping the pivot into
 *   position i+1 ensures the pivot is sorted correctly.
 *
 * COMPLEXITY:
 * - Time: O(high - low) — each element is examined once and at most swapped once.
 * - Space: O(1) — in-place partitioning, no extra arrays.
 *
 * STABILITY:
 * - Partitioning is NOT stable — swaps can reorder equal elements.
 *
 * IMPLEMENTATION NOTES / PITFALLS:
 * - The Lomuto scheme is simple but can degrade if pivot is poorly chosen
 *   (e.g., always picking the smallest or largest element).
 * - Alternatives: Hoare's scheme (two-pointer from ends) is faster in
 *   practice but slightly more complex.
 * - Always be careful with boundary conditions: use <= to include equal
 *   elements in the left partition (improves behavior with duplicates).
 *
 * WORKED EXAMPLE:
 * - Start: [3, 6, 8, 10, 1, 2] (partition from index 0 to 5, pivot = 2)
 *   i = -1, pivot = arr[5] = 2
 *   j=0: arr[0]=3, 3>2 → no swap → [3,6,8,10,1,2]
 *   j=1: arr[1]=6, 6>2 → no swap → [3,6,8,10,1,2]
 *   j=2: arr[2]=8, 8>2 → no swap → [3,6,8,10,1,2]
 *   j=3: arr[3]=10, 10>2 → no swap → [3,6,8,10,1,2]
 *   j=4: arr[4]=1, 1<=2 → i++ (i=0), swap arr[0] and arr[4] → [1,6,8,10,3,2]
 *   End: swap arr[i+1] and arr[high] → swap arr[1] and arr[5] → [1,2,8,10,3,6]
 *   Return: i+1 = 1 (pivot 2 is now at index 1)
 * - Result: [1,2,8,10,3,6] with pivot 2 in final sorted position
 *
 * @param arr: array to partition
 * @param low: starting index of partition range
 * @param high: ending index of partition range (pivot location)
 * @return: final index of the pivot after partitioning
 */
int partition(int arr[], int low, int high)
{
    // Choose the rightmost element as pivot
    int pivot = arr[high];

    // Index of smaller element, indicates the position of pivot
    int i = low - 1;

    // Traverse through all elements and compare with pivot
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;        // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(&arr[i+1], &arr[high]);
    return i + 1;       // Return the partition index
}

/**
 * QUICK SORT (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Quicksort is a divide-and-conquer algorithm. Pick a pivot, partition the
 *   array so smaller elements are left and larger are right (pivot is now in
 *   place), then recursively sort the two sides. The partitioning does most
 *   of the work; merging is trivial (unlike merge sort).
 *
 * RECURSIVE INVARIANT:
 * - After a call to `quickSort(arr, low, high)` returns, arr[low..high] is
 *   sorted in ascending order. This is maintained inductively: if both
 *   recursive calls return correctly sorted subarrays, and the pivot is in
 *   place after partitioning, the whole range is sorted.
 *
 * ALGORITHM (step-by-step):
 * 1. If low < high (more than one element):
 *    a. Call partition(arr, low, high) to find the pivot index.
 *    b. Recursively sort arr[low..pivotIndex-1].
 *    c. Recursively sort arr[pivotIndex+1..high].
 *    (The pivot itself is already in place.)
 * 2. Base case: ranges of size 0 or 1 are already sorted.
 *
 * COMPLEXITY:
 * - Best / Average case: O(n log n) — if pivot splits array reasonably evenly.
 * - Worst case: O(n^2) — if pivot is always smallest/largest (e.g., sorted
 *   input with rightmost pivot, or reverse sorted with leftmost pivot).
 *   Randomizing pivot choice or using median-of-three helps avoid this.
 * - Space: O(log n) average recursion depth; O(n) worst case if unbalanced.
 *
 * CHARACTERISTICS / TIPS:
 * - Quick sort is in-place (no extra arrays) and fast in practice due to
 *   good cache locality and low constant factors.
 * - NOT stable — equal elements may reorder due to partitioning swaps.
 * - Highly sensitive to pivot choice; randomized quicksort or median-of-three
 *   helps ensure O(n log n) expected time in adversarial cases.
 * - Hybrid approaches: use insertion sort for small subarrays (size <= 10)
 *   to reduce overhead.
 * - Tail-call optimization: after recursing on the smaller subarray, recurse
 *   on the larger one to minimize stack depth.
 *
 * EDGE CASES:
 * - Calling `quickSort(arr, 0, n-1)` for n == 0 or n == 1 is safe because
 *   the base case returns immediately.
 * - Arrays with many duplicates: partitioning with <= helps, but consider
 *   three-way partition (less-than, equal-to, greater-than) for better
 *   performance.
 *
 * WORKED EXAMPLE:
 * - Start: [3, 6, 8, 10, 1, 2, 1]
 *   Call quickSort(arr, 0, 6):
 *   - Partition from 0 to 6: pivot=1 (at index 6)
 *     Result: [1, 1, 3, 6, 8, 10, 2] with pivot at index 1
 *   - Recurse left [0..0]: single element, done
 *   - Recurse right [2..6]: [3, 6, 8, 10, 2]
 *     Partition: pivot=2 (at index 6)
 *     Result: [2, 3, 6, 8, 10] with pivot at index 2
 *     Recurse left [2..1]: invalid range, done
 *     Recurse right [3..4]: [8, 10]
 *       Partition: pivot=10, pivot=10 moves to final position
 *       Recurse left [3..3]: single element, done
 *       Recurse right [5..4]: invalid, done
 *     Recurse left [2..2]: single element, done
 *   Final sorted: [1, 1, 2, 3, 6, 8, 10] ✓
 *
 * @param arr: array to be sorted
 * @param low: starting index
 * @param high: ending index
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before partition
        quickSort(arr, low, pivotIndex - 1);

        // Recursively sort elements after partition
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate quick sort
int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Test with more cases
    printf("\n--- Additional Test Cases ---\n");
    
    // Test Case 2: Already sorted
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Already sorted: ");
    printArray(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    printf("After sort: ");
    printArray(arr2, n2);
    
    // Test Case 3: Reverse sorted
    int arr3[] = {5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nReverse sorted: ");
    printArray(arr3, n3);
    quickSort(arr3, 0, n3 - 1);
    printf("After sort: ");
    printArray(arr3, n3);
    
    return 0;
}
