#include <bits/stdc++.h>
using namespace std;

/*
Outer Loop: Iterate through the array with index i from 0 to n-1.
Assume that the current element at index i is the smallest in the unsorted part of the array. Initialize minIndex = i.

Inner Loop: For each i, run a nested loop with index j starting from i + 1 to n to find the smallest element in the unsorted portion.
Compare the current element at index arr[j] with the element at arr[minIndex].
If arr[j] < arr[minIndex], update minIndex = j (this means a smaller element has been found).

Swap: After the inner loop ends, if minIndex is not equal to i, swap the element at arr[i] with the element at arr[minIndex].

This places the smallest element found in the unsorted portion at the correct position.
Repeat: Continue the process until the whole array is sorted.

*/

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  
        for (int j = i + 1; j < n; j++) {  
            if (arr[j] < arr[minIndex])minIndex = j; 
        }
        if(minIndex != i )swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr) / sizeof(arr[0]);  

    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    return 0;
}
