/*

Geeks for Geeks and asked in amazon.
Easy solution would be to check from 0 - n-1 and return the first missing smalled element.
And the Big O - O(n)

Optimal solution: https://www.geeksforgeeks.org/find-the-first-missing-number/
Big O: O(logn) 


Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array. 
Examples 

Input: {0, 1, 2, 6, 9}, n = 5, m = 10 
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12 
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5 
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11 
Output: 8

*/



// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int findFirstMissing(int a[],  
                    int start, int end) {
    if ((end - start) < 0)                        
    {
        return end + 1; 
    } if (start != a[start]){
        return start;
    }
    int mid = (start + end) /2;
    if (a[mid] != mid)  {
        return findFirstMissing(a, start, mid);
    } else if (a[mid] == mid) {
        return findFirstMissing(a, mid + 1, end);
    }
}   

int main() 
{ 
    int arr[] = {0, 1, 2, 6, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Smallest missing element is " << 
        findFirstMissing(arr, 0, n-1) << endl; 
        return 0;
}

