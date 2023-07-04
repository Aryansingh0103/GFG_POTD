/*
Given an array arr[] of n positive integers.
 The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].
Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 
6
Explanation: 
In the given array arr[1] < arr[7]  satisfying 
the required condition (arr[i] <= arr[j])  thus 
giving the maximum difference of j - i which is
6(7-1).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIndexDiff(int arr[], int n) {
        // code here
      vector<int> leftMin(n),rightMax(n);

        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(arr[i], leftMin[i-1]);
        }

        rightMax[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(arr[i], rightMax[i+1]);
        }

        int i = 0, j = 0;
        int result = -1;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                result = max(result, j - i);
                j++;
            } else {
                i++;
            }
        }

        return result;
    }

int main() {
    int n = 9;
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};

    int result = maxIndexDiff(arr, n);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
