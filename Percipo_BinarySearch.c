#include <stdio.h>

/**
 * BINARY SEARCH ALGORITHM
 * 
 * DESCRIPTION:
 * Efficiently searches for a target value in a sorted array by repeatedly
 * dividing the search space in half, eliminating half of the remaining
 * elements in each iteration.
 * 
 * HOW IT WORKS:
 * 1. Initialize two pointers: left (start) and right (end) of array
 * 2. While search space exists (left <= right):
 *    a. Calculate middle index
 *    b. Compare target with middle element
 *    c. If equal, target found - return index
 *    d. If target > middle, search right half (move left pointer right)
 *    e. If target < middle, search left half (move right pointer left)
 * 3. If loop ends without finding target, return -1
 * 
 * REQUIREMENTS:
 * - Array MUST be sorted in ascending order
 * - Only works on sorted data structures
 * 
 * TIME COMPLEXITY: O(log n)
 * - Each iteration halves the search space
 * - Maximum iterations = log₂(n)
 * 
 * SPACE COMPLEXITY: O(1)
 * - Only uses constant extra space for pointers
 * 
 * EXAMPLE:
 * Array: [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]
 * Target: 23
 * Steps:
 *   left=0, right=10, mid=5 → arr[5]=23 → Found! Return 5
 * 
 * @param arr: sorted array of integers
 * @param n: size of the array
 * @param target: value to search for
 * @return: index of target if found, -1 otherwise
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