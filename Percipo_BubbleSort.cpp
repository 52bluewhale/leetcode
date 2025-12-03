#include <iostream>
#include <vector>
using namespace std;

/**
 * Performs bubble sort on a vector (optimized version)
 * Repeatedly swaps adjacent elements if they are in wrong order
 * @param arr: vector to be sorted
 */
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        // Last i element are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if current element is greater than next
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // If no swapping happened, array is already sorted
        if (!swapped) break;
    }
}

/**
 * Prints vector elements
 * @param arr: vector to print
 */
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Main function to demonstrate bubble sort
 */
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    printArray(arr);
    
    bubbleSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    // Test with already sorted array
    vector<int> sortedArr = {1, 2, 3, 4, 5};
    
    cout << "\nAlready sorted array: ";
    printArray(sortedArr);
    
    bubbleSort(sortedArr);
    
    cout << "After bubble sort: ";
    printArray(sortedArr);
    
    return 0;
}