/*

219. Contains Duplicate II.

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0;i<nums.size();i++) {
            if ((m.count(nums[i])) && (i - m[nums[i]] <= k)) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
    
};
