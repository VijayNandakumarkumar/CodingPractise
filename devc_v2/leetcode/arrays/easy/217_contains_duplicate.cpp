/*

217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i =0;i<(int)nums.size();i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
        
    }
};
