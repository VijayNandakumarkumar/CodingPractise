/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.


*/

// same optimised bin search solution but with recursion.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findBinPeak(0, nums.size()-1, nums);
    }
    int findBinPeak(int start, int end, vector<int>& nums) {
        if (start >= end) {
            return start;
        }
        
        int mid = (start + end) / 2;
        
        if (nums[mid] < nums[mid+1]) {
            return findBinPeak(mid + 1, end, nums);
        }
        return findBinPeak(start, mid, nums);
    }
};


#include<bits/stdc++.h>
using namespace std;


// Optimised bin search solution.

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
    }
    }
	return left; 
}

int findPeakElement(vector<int>& nums) {
    for(int i=0;i<(int)nums.size()-1;i++){
        if((nums[i]> nums[i+1])){
            return i;
        }
    }
	return (int)nums.size()-1;
}


int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(8);
	cout<<findPeakElement(v);
	return 0;
}
