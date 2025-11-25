/**
 * Median of Two Sorted Arrays - C Solution
 * Time Complexity: O(log(min(m,n)))
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <limits.h>

/**
 * Macro to find minimum and maximum of two integers
 */
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define max(a, b) ((a) ? (b) ? (a) : (b))

/**
 * Helper function to find minimum of two integers
 * @param a First integer
 * @param b Second integer
 * @return The smaller of the two integers
 */
int min(int a, int b) 
{
    return a < b ? a : b;
}

/**
 * Helper function to find maximum of two integers
 * @param a First integer
 * @param b Second integer
 * @return The larger of the two integers
 */
int max(int a, int b) 
{
    return a > b ? a : b;
}

/**
 * Find the median of two sorted arrays using binary search
 * 
 * Algorithm:
 * 1. Ensure nums1 is the smaller array (for optimization)
 * 2. Use binary search on the smaller array to find the correct partition
 * 3. A partition divides arrays into left and right halves
 * 4. Valid partition: max(left) <= min(right) for both arrays
 * 5. Calculate median based on total length (odd/even)
 * 
 * @param nums1 First sorted array
 * @param nums1Size Size of first array
 * @param nums2 Second sorted array
 * @param nums2Size Size of second array
 * @return The median value as a double
 */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    // Ensure nums1 is the smaller array for optimization
    // Binary search on smaller array is more effiecient
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    // Binary search boundaries on nums1
    int low = 0;
    int high = m;

    // Calculate the position where we need to split the combined arrays
    // For median, we need half of total elements on the left side
    // Adding 1 handles both odd and even cases correctly
    int halfLen = (m + n + 1)/2;

    while (low <= high)
    {
        
    }
}