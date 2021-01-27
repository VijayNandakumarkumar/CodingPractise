/*

62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6


*/

//Solution 1: DP top-down.
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        vector<vector<int>> v (m, vector<int> (n, 0));
        for(int i = 0;i < n; i++) {
            v[0][i] = 1;
        }
        for(int i = 0;i < m; i++) {
            v[i][0] = 1;
        }
        for(int i = 1;i < m; i++) {
            for(int j = 1;j < n; j++) {
                v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }

 //Solution 2: DP Top-Down (Time exceeding)
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }

//Solution 3: Back tracking.
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        int count = 0;
        getAllPaths(0, 0, m - 1, n - 1, count);
        return count;
    }
    void getAllPaths(int i, int j, int m, int n, int &count) {
        if ((i ==m) && (j == n)) {
            count++;
            return;
        }
        if (i <= m) {
            getAllPaths(i + 1, j, m, n, count);
        }
        if (j<=n) {
            getAllPaths(i, j + 1, m, n, count);
        }
    }
