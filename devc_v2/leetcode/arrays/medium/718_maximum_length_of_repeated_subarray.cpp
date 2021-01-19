/*

//Similar to longest common substring.

718. Maximum Length of Repeated Subarray

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].


*/


int findLength(vector<int>& A, vector<int>& B) {
        return longestCommonString(A, B);
    }
    
    int longestCommonString(vector<int>& text1, vector<int>& text2) {
        int row = text1.size();
        int col = text2.size();
        vector<vector<int> > dp(row + 1, vector<int> (col + 1, 0));
        
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
                dp[i][j] = 0;
            }
            }
        }
            return maxlen;
    }
    
