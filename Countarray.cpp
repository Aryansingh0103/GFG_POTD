/*
Given an array of positive numbers,
 the task is to find the number of possible contiguous subarrays having product less than a given number k.
 Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
*/
#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                prod = prod * a[j];
                if (prod < k) {
                    count++;
                }
                else {
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    solution s;
    vector<int> a = {1, 2, 3, 4};
    int n = a.size();
    long long k = 10;
    int result = s.countSubArrayProductLessThanK(a, n, k);
    cout << result << endl;
    return 0;
}
