/*
Quick Sort is a Divide and Conquer algorithm. 
It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array)
 and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // Choose the last element as the pivot
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
};

int main() {
    Solution solution;
    int arr[] = {7, 2, 1, 6, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    solution.quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
