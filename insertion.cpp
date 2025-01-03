#include <bits/stdc++.h>
using namespace std;

/*
1. Outer loop- Start iterating from the second element (index 1).
2. Assume the first element is already sorted.
3. For each element, find its correct position in the sorted part of the array by comparing it with previous elements.
4. inner while loop -Move larger elements one position to the right to make space for the current element.
5. Insert the current element at the correct position.
6. Repeat until the array is sorted.
*/

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Outer loop starts from 2nd element
        int key = arr[i];  // Current element to insert into sorted part
        int j = i - 1;

// Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j = j - 1;
        }
        arr[j + 1] = key;  // Insert the current element at the correct position
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, n);  

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";  // Print sorted array
    cout << endl;

    return 0;
}
