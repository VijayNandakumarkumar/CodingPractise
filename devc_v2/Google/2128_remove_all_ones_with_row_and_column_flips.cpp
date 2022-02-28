/*

2128. Remove All Ones With Row and Column Flips

You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

 

Example 1:

Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column

Example 2:

Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
Output: false
Explanation: It is impossible to remove all 1's from grid.

Example 3:

Input: grid = [[0]]
Output: true
Explanation: There are no 1's in grid.

*/

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        //Assumption here is we can either concentrate on rows or columns to flip first.
        // Basically for rows to result into same column value, the adjacent rows should either be of same patten or should be equal to each other.
        // Say row 1: -> 1 0 1
        // Say row 2: -> 0 1 0
        // here we can compare the first element of both the rows and we can see that they inversion of each other, so for these two rows considered all the remaining elements in them should be of the same pattern inverse of each other. Only then on flippiing them theyll land up as a same one.
        // Say row 1: -> 1 0 1
        // Say row 2: -> 1 0 1
        // Here we should expect both the row elements should be of the same value throughout.
        int m = grid.size();
        int n = grid[0].size();
        for (int i=1; i<m; i++) {
            bool isPattern = grid[i-1][0] != grid[i][0];
            for(int j=0; j<n; j++) {
                if (isPattern) {
                    if (grid[i][j] == grid[i-1][j]) 
                        return false;
                } else if (grid[i][j] != grid[i-1][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};