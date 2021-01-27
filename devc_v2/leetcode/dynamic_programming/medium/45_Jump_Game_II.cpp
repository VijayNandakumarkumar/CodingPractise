/*

45. Jump Game II

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

*/

//Tushar roy.
//Solution 1: Optimal (O(n)) Iteration.

int jump(vector<int>& nums) {
        if (nums.size() == 1) {
                return 0;
            }
            int count = 0;
            int i = 0;
            while (i + nums[i] < nums.size() - 1) {
                int maxVal = 0;
                int maxValIndex = 0;
                for (int j = 1; j <= nums[i]; j++) {
                    if (nums[j + i] + j > maxVal) {
                        maxVal = nums[j + i] + j;
                        maxValIndex = i + j;
                    }
                }
                i = maxValIndex;
                count++;
            }
            return count + 1;
    }


//Solution 2: Sub optimal. DP (O(n2))

int jump(vector<int>& nums) {
        vector<int> dp (nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1;i<nums.size();i++) {
            for (int j=0;j<i;j++) {
                if (i <= j+nums[j]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
