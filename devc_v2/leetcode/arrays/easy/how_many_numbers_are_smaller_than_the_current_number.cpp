/** 1365. How Many Numbers Are Smaller Than the Current Number

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you 
have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0] */

#include<bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        sort(nums.begin(), nums.end());
        map<int, int> ret_arr;
        for (int i=0;i<nums.size();i++) {
            if ((i>0) && (nums[i] == nums[i-1])) {
                continue;
            } else{
                ret_arr[nums[i]] = i;
            }
        } 
        for (int i=0;i<nums.size();i++) {
            v[i] = ret_arr[v[i]];
        }
        ret_arr.clear();
        nums.clear();
        return v;
    }
    
    int main() {
    	vector<int> v {8,1,2,2,3};
    	v = smallerNumbersThanCurrent(v);
    	for(int i=0;i<v.size();i++) {
    		cout<<v[i];
		}
		return 0;
	}
