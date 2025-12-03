#include <stdio.h>
#include <stdlib.h>

/**
 * MERGE (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Given two adjacent sorted ranges within a single array (arr[left..mid]
 *   and arr[mid+1..right]), produce a single sorted range arr[left..right]
 *   by repeatedly choosing the smaller front element from the two ranges.
 *
 * KEY INVARIANT:
 * - At any point during the merge, the elements already written to
 *   arr[left..k-1] are the smallest (k-left) elements of the multiset
 *   formed by the two input subarrays. The remaining inputs are in
 *   leftArr[i..n1-1] and rightArr[j..n2-1].
 *
 * ALGORITHM (step-by-step):
 * 1. Compute sizes n1 = mid-left+1 and n2 = right-mid. Allocate temporary
 *    arrays and copy values from the two subranges.
 * 2. Use three indices: i for leftArr, j for rightArr, k for writing into
 *    the original array starting at `left`.
 * 3. While both i < n1 and j < n2, compare leftArr[i] and rightArr[j].
 *    Copy the smaller into arr[k] and advance that index (i or j) and k.
 * 4. When one side is exhausted, copy the remaining elements from the
 *    other temporary array into arr[k..right].
 * 5. Free temporaries.
 *
 * COMPLEXITY:
 * - Time: O(n1 + n2) = O(right-left+1) for each merge operation.
 * - Space: O(n1 + n2) temporary extra memory. To avoid repeated
 *   allocations, you can allocate a single auxiliary buffer once and reuse it.
 *
 * STABILITY:
 * - This merge is stable because when leftArr[i] == rightArr[j], the
 *   implementation prefers leftArr (uses <=) so left-side elements appear
 *   before equal right-side elements in the output.
 *
 * IMPLEMENTATION NOTES / PITFALLS:
 * - Copying the correct ranges into temporaries is essential: leftArr gets
 *   values arr[left..mid] and rightArr gets arr[mid+1..right].
 * - Always check for successful allocation of temporaries in constrained
 *   environments.
 * - For very large arrays, consider iterative merge sort or in-place merge
 *   algorithms to reduce memory pressure.
 *
 * @param arr: the main array containing two sorted ranges
 * @param left: starting index of left subarray
 * @param mid: ending index of left subarray
 * @param right: ending index of right subarray
 */
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;        // Size of left subarray
    int n2 = right - mid;           // Size of right subarray

    // Create temporary arrays
    int *leftArr = (int*)malloc(n1 * sizeof(int));
    int *rightArr = (int*)malloc(n2 * sizeof(int));

    if (leftArr == NULL || rightArr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left+i];
    }
    
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid+1+j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;          // Initial index of left subarray
    int j = 0;          // Initial index of right subarray
    int k = left;       // Initial index of merged array

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        
        k++;
    }

    // Copy remaining elements of leftArr[] if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[] if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(leftArr);
    free(rightArr);
}

/**
 * MERGE SORT (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Merge sort is a divide-and-conquer algorithm: split the array into two
 *   roughly equal halves, recursively sort each half, and then merge the
 *   sorted halves. The heavy lifting is done by the merge step.
 *
 * RECURSIVE INVARIANT:
 * - After `mergeSort(arr, left, mid)` returns, arr[left..mid] is sorted. After
 *   `mergeSort(arr, mid+1, right)` returns, arr[mid+1..right] is sorted. The
 *   merge call then produces a sorted arr[left..right]. This maintains
 *   correctness by induction on the segment length.
 *
 * ALGORITHM (step-by-step):
 * 1. If left < right:
 *    a. Compute mid = left + (right-left)/2 to avoid overflow.
 *    b. Recursively call mergeSort on left half: [left..mid].
 *    c. Recursively call mergeSort on right half: [mid+1..right].
 *    d. Merge the two sorted halves with `merge`.
 * 2. Base case: segments of size 0 or 1 are already sorted.
 *
 * COMPLEXITY:
 * - Time: T(n) = 2 T(n/2) + O(n) → O(n log n) in all cases (best/avg/worst).
 * - Space: O(n) auxiliary (for merging) plus O(log n) recursion stack depth.
 *
 * CHARACTERISTICS / TIPS:
 * - Stable when using a stable merge implementation.
 * - Predictable O(n log n) time makes it a good general-purpose sort.
 * - Good for external sorting (can be adapted to work with disk) because
 *   merging can stream through data.
 * - Optimization: allocate a single auxiliary buffer once and pass it down
 *   to `merge` to avoid repeated malloc/free overhead.
 * - Use insertion sort for small subarrays (e.g., size <= 16) to reduce
 *   constant factors; this hybrid approach often improves real-world speed.
 *
 * EDGE CASES:
 * - Calling `mergeSort(arr, 0, n-1)` for n == 0 is safe (left=0, right=-1,
 *   left < right is false). Still, callers should ensure array pointer is
 *   valid when n > 0.
 *
 * @param arr: array to be sorted
 * @param left: starting index
 * @param right: ending index
 */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point to divide array into two halves
        int mid = left + (right - left)/2;

        // Recursively sort first half
        mergeSort(arr, left, mid);

        // Recursively sort second half
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
 * Main function to demonstrate merge sort
 */
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}