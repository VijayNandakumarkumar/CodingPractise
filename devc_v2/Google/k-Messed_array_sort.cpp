/*

K-Messed Array Sort

Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
Examples: 
 

Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
         k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}


GEEKS for GEEKS: https://www.geeksforgeeks.org/nearly-sorted-algorithm/

*/

// Solution - 1 Optimal (O(nlogk)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
int n = arr.size();
vector<int> v;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i<n; i++) {
    if (q.size() <= k+1) {
      q.push(arr[i]);
      continue;
    }
    v.push_back(q.top());
    cout<<q.top()<<" ";
    q.pop();
    q.push(arr[i]);
  }
  
//  cout<<q.size();
  while (!q.empty()) {
    v.push_back(q.top());
    cout<<q.top()<<" ";
    q.pop();
  }
  return v;
}

// Solution - 2 SuubOptimal (MergeSort O(nlogn)

// Solution - 3 Sub Optimal (Our solution)

vector<int> v (arr.begin(), arr.end());
  int n = arr.size();

   
   for (int i = 0; i < n; i++) {
    for (int j = i + k; j > i; j--) {
      if (j> n-1)
        j=n-1;
      if (v[i] > v[j]) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
  
