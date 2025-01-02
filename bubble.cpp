/*
The outer loop runs n-1 times (where n is the number of elements).
The inner loop compares adjacent elements, and if they are out of order (i.e., arr[j] > arr[j+1]), they are swapped.
If no elements were swapped in a particular pass (indicating the array is already sorted), the swapped flag will remain false, and the loop terminates early, saving unnecessary iterations.

*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i =0 ;i< n-1 ;i++){
        bool swapped =0;
        for( int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=1;
            }
        }
        if(!swapped)break;
    }
    
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " "; 
    cout << endl;

    bubbleSort(arr, n);  

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";  // Print sorted array
    cout << endl;

    return 0;
}
