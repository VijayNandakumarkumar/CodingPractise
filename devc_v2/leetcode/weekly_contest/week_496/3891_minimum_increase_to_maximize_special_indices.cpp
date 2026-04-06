/*

3891. Minimum Increase to Maximize Special Indices

You are given an integer array nums of length n.

An index i (0 < i < n - 1) is special if nums[i] > nums[i - 1] and nums[i] > nums[i + 1].

You may perform operations where you choose any index i and increase nums[i] by 1.

Your goal is to:

Maximize the number of special indices.
Minimize the total number of operations required to achieve that maximum.
Return an integer denoting the minimum total number of operations required.

 

Example 1:

Input: nums = [1,2,2]

Output: 1

Explanation:​​​​​​​

Start with nums = [1, 2, 2].
Increase nums[1] by 1, array becomes [1, 3, 2].
The final array is [1, 3, 2] has 1 special index, which is the maximum achievable.
It is impossible to achieve this number of special indices with fewer operations. Thus, the answer is 1.
Example 2:

Input: nums = [2,1,1,3]

Output: 2

Explanation:​​​​​​​

Start with nums = [2, 1, 1, 3].
Perform 2 operations at index 1, array becomes [2, 3, 1, 3].
The final array is [2, 3, 1, 3] has 1 special index, which is the maximum achievable. Thus, the answer is 2.
Example 3:

Input: nums = [5,2,1,4,3]

Output: 4

Explanation:​​​​​​​​​​​​​​​​​​​​​

Start with nums = [5, 2, 1, 4, 3].
Perform 4 operations at index 1, array becomes [5, 6, 1, 4, 3].
The final array is [5, 6, 1, 4, 3] has 2 special indices, which is the maximum achievable. Thus, the answer is 4.​​​​​​​
 

Constraints:

3 <= n <= 105
1 <= nums[i] <= 109

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

*/


//Code with Vick
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int dp0 = 0, dp1 = INT_MIN;
        long long cost0 = 0, cost1 = INT_MAX;

        for (int i=1; i<= nums.size()-2; i++) {
            long long needed = max(nums[i-1], nums[i+1]) + 1LL;
            long long cur_cost = max(0LL, (needed - nums[i]));

            // skipping ith index
            int ndp0;
            long long ncost0;

            if (dp0 > dp1) {
                ndp0 = dp0;
                ncost0 = cost0;
            } else if (dp0 < dp1) {
                ndp0 = dp1;
                ncost0 = cost1;
            } else {
                ndp0 = dp0;
                ncost0 = min(cost0, cost1);
            }

            // Taking ith index
            int ndp1 = dp0 + 1;
            long long ncost1 = cost0 + cur_cost;


            dp0 = ndp0;
            cost0 = ncost0;
            
            dp1 = ndp1;
            cost1 = ncost1;
        }

        if (dp0 > dp1) return cost0;
        if (dp0 < dp1) return cost1;
        return min(cost0, cost1);
    }
};
