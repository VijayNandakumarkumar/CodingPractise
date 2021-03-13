/*

Pramp

Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.

Examples:

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i.

*/

#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int> &arr) 
{
  // your code goes here
  /*
      [-8, 1, 2, 3, 100]
        0. 1. 2. 3.  4
  */
  int n = arr.size();
  int low = 0, high = n-1;
  int resInd = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == mid) {
      high = mid - 1;
      resIndex = mid;
    }
    else if (arr[mid] < mid) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return resIndex;
}

int main() {
  vector<int> v = {-8, 1, 2, 50, 100};
  cout<<indexEqualsValueSearch(v);
  return 0;
}

// [-8, 0, 2,3,5]
//  0 1 2 3


