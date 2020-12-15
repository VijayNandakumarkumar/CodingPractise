//find-the-element-that-appears-once-in-a-sorted-array

/*
Given a sorted array in which all elements appear twice (one after one) and one element appears only once. Find that element in O(log n) complexity.

Example: 

Input:   arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
Output:  4

Input:   arr[] = {1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8}
Output:  8
*/

// C++ program to find the element that
// appears only once
#include <iostream>
using namespace std;
 
// A Binary Search based function to find
// the element that appears only once
void search(int arr[], int low, int high)
{
 
    // Base cases
    if (low > high)
        return;
 
    if (low == high) {
        cout << "The required element is " << arr[low];
        return;
    }
 
    // Find the middle point
    int mid = (low + high) / 2;
 
    // If mid is even and element next to mid is
    // same as mid, then output element lies on
    // right side, else on left side
    if (mid % 2 == 0) {
        if (arr[mid] == arr[mid + 1])
            search(arr, mid + 2, high);
        else
            search(arr, low, mid);
    }
 
    // If mid is odd
    else {
        if (arr[mid] == arr[mid - 1])
            search(arr, mid + 1, high);
        else
            search(arr, low, mid - 1);
    }
}
 
// Driver code
int main()
{
    int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);
 
    search(arr, 0, len - 1);
 
    return 0;
}
