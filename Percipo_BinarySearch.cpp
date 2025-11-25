#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs binary search on a sorted vector
 * @param arr: sorted vector of integers
 * @param target: value to search for
 * @return: index of target if found, -1 otherwise
 */
int binarySearch(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        // Calculate mid member to avoid overflow
        int mid = left + (right - left)/2;

        // Check if target is at mid
        if (arr[mid] == target) return mid;

        // If target is greater, ignore left side
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // If target is smaller, ignore right side
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

/**
 * Main function to demonstrate binary search
 */
int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int target = 23;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in array" << endl;
    }
    
    // Test with non-existent element
    target = 100;
    result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in array" << endl;
    }
    
    return 0;
}