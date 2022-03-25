/*

1218. Longest Arithmetic Subsequence of Given Difference

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].

*/

class Solution {
public:
// Our first Solution    
// int longestSubsequence(vector<int>& arr, int difference) {
//         int n = arr.size();
//         vector<int> dp(n, 1);
        
//         int maxLen=1;
//         for (int i=1; i<n; i++) {
//             for (int j=0; j<i; j++) {
//                 if (arr[i] - arr[j] == difference) {
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//                 maxLen = max(maxLen, dp[i]);
//             }
//         }
//         return maxLen;
//     }
    
    // From discussion, we were also thinking in the same path.
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        dp[arr[0]] = 1;
        
        int maxLen=1;
        for (int i=1; i<n; i++) {
            int prevNum = arr[i] - difference;
            if (dp[prevNum] == 0) {
                dp[arr[i]] = 1;
            } else {
                dp[arr[i]] = dp[prevNum]+1;
                maxLen = max(maxLen, dp[arr[i]]);
            }
        }
        return maxLen;
    }
};