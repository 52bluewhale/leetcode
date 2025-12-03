#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs selection sort on a vector
 * Finds minimum element and places it at the beginning in each iteration
 * @param arr: vector to be sorted
 */
void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        if (minIndex != i) swap(arr[i], arr[minIndex]);
    }
}

/**
 * Prints vector elements
 * @param arr: vector to print
 */
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Main function to demonstrate selection sort
 */
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    printArray(arr);
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}