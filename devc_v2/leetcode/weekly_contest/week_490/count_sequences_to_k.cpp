/*
3850. Count Sequences to K

You are given an integer array nums, and an integer k.

Start with an initial value val = 1 and process nums from left to right. At each index i, you must choose exactly one of the following actions:

Multiply val by nums[i].
Divide val by nums[i].
Leave val unchanged.
After processing all elements, val is considered equal to k only if its final rational value exactly equals k.

Return the count of distinct sequences of choices that result in val == k.

Note: Division is rational (exact), not integer division. For example, 2 / 4 = 1 / 2.

 

Example 1:

Input: nums = [2,3,2], k = 6

Output: 2

Explanation:

The following 2 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
1	Multiply: val = 1 * 2 = 2	Multiply: val = 2 * 3 = 6	Leave val unchanged	6
2	Leave val unchanged	Multiply: val = 1 * 3 = 3	Multiply: val = 3 * 2 = 6	6
Example 2:

Input: nums = [4,6,3], k = 2

Output: 2

Explanation:

The following 2 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
1	Multiply: val = 1 * 4 = 4	Divide: val = 4 / 6 = 2 / 3	Multiply: val = (2 / 3) * 3 = 2	2
2	Leave val unchanged	Multiply: val = 1 * 6 = 6	Divide: val = 6 / 3 = 2	2
Example 3:

Input: nums = [1,5], k = 1

Output: 3

Explanation:

The following 3 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Final val
1	Multiply: val = 1 * 1 = 1	Leave val unchanged	1
2	Divide: val = 1 / 1 = 1	Leave val unchanged	1
3	Leave val unchanged	Leave val unchanged	1
 

Constraints:

1 <= nums.length <= 19
1 <= nums[i] <= 6
1 <= k <= 1015

*/

// Code Throughts and GPT

class Solution {
public:
    vector<int> target;
    vector<vector<int>> prime;
    int res=0;
    int n;
    map<tuple<int, int, int, int>, int> dp;
    int countSequences(vector<int>& nums, long long k) {
        // brute force method is to have 3 for loops one for each operation. 1. Take the number for multiplication operation, 2. Take the number for division operation, 3. leave the number. This at worst case could be O(n * 3) where n is the size of nums and 3 for 3 operations.
        // Next case is frequency check, go through nums and create a frequency map and also, create a next operator map which basically tell - if I pick x, then k/x = y, we will check if y exists in the freq map if so we will pick x.
        // Third should be the optimal approach and we need to check how to do this.
    target.assign(3, 0);
    n = nums.size();
    target = primeFactors(k);
    if (target.empty()) {
        return 0;
    }
    prime.resize(n);

    for (int i=0; i<n; i++) {
        prime[i] = primeFactors(nums[i]);
    }

    return dfs(0, 0, 0, 0);
    }

    int dfs(int i, int c2, int c3, int c5) {
        if (i == n) {
            vector<int> temp_result {c2, c3, c5};
            if (target == temp_result){
                return 1;
            }
            return 0;
        }
        auto key = make_tuple(i,c2,c3,c5);
        if (dp.count(key))
            return dp[key];
        int temp_res = 0;
        temp_res += dfs(i+1, c2, c3, c5);
        temp_res += dfs(i+1, c2+prime[i][0], c3+prime[i][1], c5+prime[i][2]);
        temp_res += dfs(i+1, c2-prime[i][0], c3-prime[i][1], c5-prime[i][2]);
        dp[{i,c2,c3,c5}] = temp_res;
        return temp_res;
    }


    vector<int> primeFactors(long long x) {
        vector<int> primes {2,3,5};
        vector<int> result (3, 0);
        for (int i=0; i<3; i++) {
            while (x%primes[i] == 0) {
                result[i]++;
                x = x/primes[i];
            }
        }
        if (x != 1) {
            return {};
        }
        return result;
    }
};
