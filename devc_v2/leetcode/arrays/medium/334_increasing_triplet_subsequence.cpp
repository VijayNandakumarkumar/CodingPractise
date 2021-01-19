/*


334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

*/


//DP
    // bool increasingTriplet(vector<int>& nums) {
    //     if (nums.size() == 0 || nums.size() < 3) {
    //         return false;
    //     }
    //     vector<int> dp(nums.size(), 1);
    //     int max_len = 0;
    //     for(int i = 1;i<nums.size();i++) {
    //         for(int j = 0;j<i;j++) {
    //             if (nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //         max_len = max(max_len, dp[i]);
    //         if (max_len >= 3) {
    //             return true;
    //         }
    //     }
    //     return false;   
    // }
    
    //Iterative
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() < 3) {
            return false;
        }
        int mid = INT_MAX, left = INT_MAX;
        
        for(int i = 0;i<nums.size();i++) {
            if (nums[i] > mid) {
                return true;
            } else if ((nums[i] < mid) && (nums[i] > left)) {
                mid = nums[i];
            } else if (nums[i] < left) {
                left = nums[i];
            }
        }
        return false;   
    }
