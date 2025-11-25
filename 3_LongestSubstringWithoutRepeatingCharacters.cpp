/*
 * LeetCode: Longest Substring Without Repeating Characters
 * Language: C++
 * Algorithm: Sliding Window with Hash Map (unordered_map)
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
    public:
       /*
        * Finds the length of the longest substring without repeating characters
        * 
        * @param s: Input string to process
        * @return: Length of longest substring with unique characters
        * 
        * Algorithm:
        * - Uses sliding window technique with two pointers (left, right)
        * - unordered_map tracks the last seen position of each character
        * - When duplicate found, move left pointer past the previous occurrence
        * - Time Complexity: O(n) where n is string length
        * - Space Complexity: O(min(n, m)) where m is charset size
        */ 
        int lengthOfLongestSubstring(string s)
        {
            // Hash map to store last seen index of each character
            unordered_map<char, int> lastSeen;

            // Store the maximum length found
            int maxLength = 0;
            // Left pointer of the sliding window
            int left = 0;

            // Right pointer traverses the entire string
            for (int right = 0; right < s.length(); right ++)
            {
                char currentChar = s[right];

                // If character exists in map and is within current window
                if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= left)
                {
                    lastSeen[currentChar] >= left;
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
};

/*
 * Test function to demonstrate the solution
 */
int main() {
    Solution solution;
    
    // Test cases
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";
    string test4 = "";
    string test5 = "dvdf";
    string test6 = "abba";
    
    cout << "Test 1: \"" << test1 << "\" -> " 
         << solution.lengthOfLongestSubstring(test1) << endl;
    cout << "Test 2: \"" << test2 << "\" -> " 
         << solution.lengthOfLongestSubstring(test2) << endl;
    cout << "Test 3: \"" << test3 << "\" -> " 
         << solution.lengthOfLongestSubstring(test3) << endl;
    cout << "Test 4: \"" << test4 << "\" -> " 
         << solution.lengthOfLongestSubstring(test4) << endl;
    cout << "Test 5: \"" << test5 << "\" -> " 
         << solution.lengthOfLongestSubstring(test5) << endl;
    cout << "Test 6: \"" << test6 << "\" -> " 
         << solution.lengthOfLongestSubstring(test6) << endl;
    
    return 0;
}