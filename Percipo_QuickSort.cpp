#include <iostream>
#include <vector>
using namespace std;

// Swaps two elements using reference parameters
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array and returns the pivot index
// Places smaller elements to the left, larger to the right
int partition(vector<int> &arr, int low, int high)
{
    // Choose the rightmost element as pivot
    int pivot = arr[high];

    // Index of smaller element, indicates the position of pivot
    int i = low - 1;

    // Traverse through all elements and compare with pivot
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;            // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(arr[i+1], arr[high]);
    return i+1;     // Return the partition index
}

// Main quick sort function - recursively sorts the array
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before partition
        quickSort(arr, low, pivotIndex - 1);

        // Recursively sort elements after partition
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to demonstrate quick sort
int main() {
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    
    cout << "Original array: ";
    printArray(arr);
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    // Test with more cases
    cout << "\n--- Additional Test Cases ---" << endl;
    
    // Test Case 2: Already sorted
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Already sorted: ";
    printArray(arr2);
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "After sort: ";
    printArray(arr2);
    
    // Test Case 3: Reverse sorted
    vector<int> arr3 = {5, 4, 3, 2, 1};
    cout << "\nReverse sorted: ";
    printArray(arr3);
    quickSort(arr3, 0, arr3.size() - 1);
    cout << "After sort: ";
    printArray(arr3);
    
    // Test Case 4: With duplicates
    vector<int> arr4 = {7, 7, 7, 7};
    cout << "\nAll same elements: ";
    printArray(arr4);
    quickSort(arr4, 0, arr4.size() - 1);
    cout << "After sort: ";
    printArray(arr4);
    
    return 0;
}