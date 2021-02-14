/*

1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

*/

// Solution-1 (O(nm) techdose)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp (m, vector<int> (n, 0));
        int count = 0;
        for (int i = 0; i<m; i++) {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        
        for (int i = 1; i<n; i++) {
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }
        cout<<count;
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};
