/*

941. Valid Mountain Array

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]


Input: arr = [2,1]
Output: false


Input: arr = [3,5,5]
Output: false

Input: arr = [0,3,2,1]
Output: true

*/


class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n = a.size();
        if (n < 3) {
            return false;
        }
        int i = 0;
        while((i + 1 < n) && (a[i] < a[i+1])) {
            i++;
        }
        if (i == n-1 || i == 0) {
            return false;
        }
        while((i + 1 <n) && (a[i] > a[i+1])) {
            i++;
        }
        return (i == n-1);
    }
};
