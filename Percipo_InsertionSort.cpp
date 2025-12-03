#include <iostream>
#include <vector>
using namespace std;

/**
 * Performs insertion sort on a vector
 * Builds sorted array one element at a time by inserting elements into their correct position
 * @param arr: vector to be sorted
 */
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // Start from second element (first is already "sorted")
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        // to make space for key
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        // Insert key at its correct position
        arr[j+1] = key;
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
 * Main function to demonstrate insertion sort
 */
int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    // Test with nearly sorted array
    vector<int> nearlySorted = {2, 3, 4, 5, 1};
    
    cout << "\nNearly sorted array: ";
    printArray(nearlySorted);
    
    insertionSort(nearlySorted);
    
    cout << "After insertion sort: ";
    printArray(nearlySorted);
    
    return 0;
}