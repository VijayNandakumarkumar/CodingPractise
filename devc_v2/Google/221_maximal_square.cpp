/*

//DP - similar to 1277 count square sub matrices.
//TechDose

221. Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int largestArea = 0;
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for (int i = 0; i<m; i++) {
            cout<<"ok";
            dp[i][0] = matrix[i][0] - '0';
            largestArea = (matrix[i][0] - '0' > largestArea) ? matrix[i][0] - '0': largestArea;
        }
        
        for (int i = 0; i<n; i++) {
            cout<<"ko";
            dp[0][i] = matrix[0][i] - '0';
            largestArea = (matrix[0][i] - '0' > largestArea) ? matrix[0][i] - '0': largestArea;
        }
        cout<<"ll";
        for (int i = 1; i<m; i++) {
            for (int j = 1; j<n; j++) {
                cout<<"In here";
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    largestArea = (dp[i][j] > largestArea) ? dp[i][j]: largestArea;
                    cout<<largestArea<<"\n";
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return largestArea * largestArea;
    }
};
