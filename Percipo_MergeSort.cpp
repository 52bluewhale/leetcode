#include <iostream>
#include <vector>
using namespace std;

/**
 * Merges two sorted subarrays into one sorted array
 * @param arr: the main vector
 * @param left: starting index of left subarray
 * @param mid: ending index of left subarray
 * @param right: ending index of right subarray
 */
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;        // Size of left subarray
    int n2 = right - mid;           // Size of right subarray

    // Create temporary vector
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary vector
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary vectors back into arr[left..right]
    int i = 0;          // Initial index of left subarray
    int j = 0;          // Initial index of right subarray
    int k = left;       // Initial index or merged array

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of leftArr if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * Performs merge sort using divide-and-conquer approach
 * @param arr: vector to be sorted
 * @param left: starting index
 * @param right: ending index
 */
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point to divide array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort first half
        mergeSort(arr, left, mid);

        // Recursively sort second half
        mergeSort(arr, mid + 1, right);

        // Merge two sorted halves
        merge(arr, left, mid, right);
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
 * Main function to demonstrate merge sort
 */
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Original array: ";
    printArray(arr);
    
    mergeSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}