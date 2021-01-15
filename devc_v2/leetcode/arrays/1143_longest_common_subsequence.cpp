/*

Back to Back SWE.

1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.length();
        int col = text2.length();
        vector<vector<int> > dp(row + 1, vector<int> (col + 1, 0));
        // for (int i = 0; i< row +1;i++) {
        //     for (int j = 0; j< col +1;j++) {
        //         cout<<dp[i][j]<<" ";
        // }
        //     cout<<"\n";
        // }
        int maxlen = 0;
        int count = 0;
        for (int i = 1; i< row +1;i++) {
            for (int j = 1; j< col +1;j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j - 1] + 1;
                if ((dp[i-1][j - 1] + 1) > maxlen) {
                    maxlen = dp[i-1][j - 1] + 1;
                }
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            }
        }
          
            return maxlen;
    }
};
