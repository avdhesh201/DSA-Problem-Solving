#include <bits/stdc++.h>
using namespace std;

/*
Heap Sort Algorithm:
1. Build a Max Heap from the array.
2. Extract the largest element (root of the heap) and move it to the end of the array.
3. Reduce the heap size by 1 and heapify the root to maintain the Max Heap property.
4. Repeat the process until the heap size becomes 1.
*/

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])largest = left;
    
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])largest = right;
    
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap root with the largest child
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build a Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)heapify(arr, n, i);
    
    // Step 2: Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to the end
        // Reduce heap size and heapify the root
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    return 0;
}
