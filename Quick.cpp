#include <bits/stdc++.h>
using namespace std;

/*
Quick Sort Algorithm:
1. Choose a pivot element from the array (e.g., the last element).
2. Partition the array:
   - Place elements smaller than the pivot to its left.
   - Place elements larger than the pivot to its right.
3. Recursively apply Quick Sort to the left and right subarrays.
4. Base case: Stop recursion when the subarray size is 1 or 0.
*/

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element  2.1
            swap(arr[i], arr[j]);  // Swap arr[i] and arr[j]
        }
    }

    swap(arr[i + 1], arr[high]);  // Place pivot in the correct position
    return (i + 1);  // Return the pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";  
    cout << endl;

    quickSort(arr, 0, n - 1);  

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " "; 
    cout << endl;

    return 0;
}
