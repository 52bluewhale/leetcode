#include <stdio.h>

/**
 * BINARY SEARCH - LECTURE NOTES
 *
 * IDEA / INTUITION:
 * - Binary search exploits order. If the array is sorted, a single comparison
 *   with the middle element lets you discard half of the possible positions
 *   for the target. Repeat this halving until you either find the element or
 *   the search space is empty.
 *
 * KEY INVARIANT:
 * - At the start of each loop iteration, the target (if present) must lie
 *   within the interval [left, right]. Maintaining this invariant is the
 *   reason the algorithm is correct.
 *
 * ALGORITHM (step-by-step):
 * 1. Initialize `left = 0`, `right = n - 1` to represent the full array.
 * 2. While `left <= right` (non-empty interval):
 *    a. Compute `mid = left + (right - left) / 2` to avoid overflow.
 *    b. If `arr[mid] == target` → return `mid` (found).
 *    c. If `arr[mid] < target` → the target must be in (mid+1 .. right),
 *       so set `left = mid + 1`.
 *    d. If `arr[mid] > target` → the target must be in (left .. mid-1),
 *       so set `right = mid - 1`.
 * 3. If the loop exits, the target is not in the array → return -1.
 *
 * PROOF SKETCH / CORRECTNESS:
 * - Initialization: [left, right] = [0, n-1] obviously contains the target if
 *   it's in the array.
 * - Maintenance: After a comparison with `arr[mid]`, we update either left
 *   or right so that the invariant holds (we always keep the interval that
 *   could still contain the target).
 * - Termination: The loop ends when left > right, meaning the search interval
 *   is empty, so the target isn't present.
 *
 * EXAMPLE (detailed trace):
 *   Array: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78], target = 23
 *   - Step 0: left=0, right=10, mid=5 → arr[5]=23 → match → return 5
 *
 * Another example (target = 20, not present):
 *   - Step 0: left=0, right=10, mid=5 → arr[5]=23; 23 > 20 → right=4
 *   - Step 1: left=0, right=4,  mid=2 → arr[2]=8; 8 < 20  → left=3
 *   - Step 2: left=3, right=4,  mid=3 → arr[3]=12; 12 < 20 → left=4
 *   - Step 3: left=4, right=4,  mid=4 → arr[4]=16; 16 < 20 → left=5
 *   - Now left=5 > right=4 → stop, return -1
 *
 * COMMON PITFALLS / TIPS:
 * - Always use `left + (right - left) / 2` to compute mid to prevent overflow
 *   when `left + right` could exceed integer range.
 * - Decide whether your binary search should be inclusive/exclusive on
 *   endpoints; here it's inclusive (`left <= right`). Other variants use
 *   `[left, right)` intervals and adjust accordingly.
 * - For duplicates: this version returns any matching index. To find first or
 *   last occurrence, adjust how you move pointers when equal.
 *
 * VARIATIONS / USE CASES:
 * - Lower bound / upper bound (first element >= target, first element >
 *   target).
 * - Binary search on answer space (e.g., searching minimal feasible value).
 *
 * COMPLEXITY:
 * - Time: O(log n) — each iteration halves the interval.
 * - Space: O(1) — only a few integer variables.
 *
 * @param arr: sorted array of integers
 * @param n: size of the array
 * @param target: value to search for
 * @return: index of target if found, -1 if not found
 */
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        // Calculate mid index to avoid overflow
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target) return mid;

        // If target is greater than arr[mid], ignore the left side
        if (arr[mid] < target) left = mid + 1;
        
        // If target is smaller than arr[mid], ignore the right side
        if (arr[mid] > target) right = mid - 1;
    }

    // Target not found
    return -1;
}

/**
 * Main function to demonstrate binary search
 */
int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, n, target);

    if (result != -1) 
    {
        printf("Element %d found at index %d\n", target, result);
    } else 
    {
        printf("Element %d not found in array\n", target);
    }

    // Test with non-existent element
    target = 100;
    result = binarySearch(arr, n, target);
    
    if (result != -1) 
    {
        printf("Element %d found at index %d\n", target, result);
    } else 
    {
        printf("Element %d not found in array\n", target);
    }
    
    return 0;
}