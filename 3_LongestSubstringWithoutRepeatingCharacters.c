/*
 * LeetCode: Longest Substring Without Repeating Characters
 * Language: C
 * Algorithm: Sliding Window with Hash Map
 */

#include <stdio.h>
#include <string.h>

/*
 * Returns the maximum of two integers
 * Used to track the maximum substring length
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/*
 * Finds the length of the longest substring without repeating characters
 * 
 * @param s: Input string to process
 * @return: Length of longest substring with unique characters
 * 
 * Algorithm:
 * - Uses sliding window technique with two pointers (left, right)
 * - Hash array tracks the last seen position of each character
 * - When duplicate found, move left pointer past the previous occurrence
 * - Time Complexity: O(n) where n is string length
 * - Space Complexity: O(1) - fixed size array of 128 (ASCII characters)
 */
int lengthOfLongestSubstring(char *s)
{
    // Hash array to store last seen index of each ASCII character
    // Initialize all positions to -1 (not seen)
    int lastSeen[128];
    for (int i = 0; i < 128; i++)
    {
        lastSeen[i] = -1;
    }

    int maxLength = 0;      // Store the maximum length found
    int left = 0;           // Left pointer of the sliding window

    // Right pointer traverses the entire string
    for (int right = 0; s[right] != '\0'; right++)
    {
        char currentChar = s[right];

        // If character was seen before and is within current window
        if (lastSeen[currentChar] >= left)
        {
            // Move left pointer to exclude the previous occurrence
            left = lastSeen[currentChar] + 1;
        }

        // Update the last seen position of current character
        lastSeen[currentChar] = right;

        // Calculate current window length and update maximum
        int currentLength = right - left + 1;
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

/*
 * Test function to demonstrate the solution
 */
int main() {
    // Test cases
    char test1[] = "abcabcbb";
    char test2[] = "bbbbb";
    char test3[] = "pwwkew";
    char test4[] = "";
    char test5[] = "dvdf";
    
    printf("Test 1: \"%s\" -> %d\n", test1, lengthOfLongestSubstring(test1));
    printf("Test 2: \"%s\" -> %d\n", test2, lengthOfLongestSubstring(test2));
    printf("Test 3: \"%s\" -> %d\n", test3, lengthOfLongestSubstring(test3));
    printf("Test 4: \"%s\" -> %d\n", test4, lengthOfLongestSubstring(test4));
    printf("Test 5: \"%s\" -> %d\n", test5, lengthOfLongestSubstring(test5));
    
    return 0;
}