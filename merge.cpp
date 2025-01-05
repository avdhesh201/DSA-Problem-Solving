#include <bits/stdc++.h>
using namespace std;

/*
Merge Sort Algorithm:
1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the two sorted halves by comparing the elements and arranging them in order.
4. Repeat the process until the entire array is sorted.

Merge Function:
1. Create temporary arrays for the left and right subarrays.
2. Copy elements into the temporary arrays.
3. Merge the elements from both temporary arrays back into the original array in sorted order.
*/

// Merge function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;  // Size of the right subarray

    // Create temporary arrays for left and right subarrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)leftArr[i] = arr[left + i];
    
    for (int j = 0; j < n2; j++)rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into the original array
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } 
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
        if (left >= right)return;
        // Find the middle point of the array
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(arr, left, mid);

        // Recursively sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]);  

    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);  

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";  
    cout << endl;

    return 0;
}
