/*

695. Max Area of Island

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]

*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0, area = 0;
        for (int i =0;i<row;i++) {
            for (int j = 0;j<col;j++) {
                if (grid[i][j] == 1) {
                    area = getTotalArea(grid, i, j, row, col, 0);
                    count = max(count, area);
                }
            }
        }
        return count;
    }
    int getTotalArea(vector<vector<int>>& grid, int i, int j, int row, int col, int area) {
        if(i<0 || i >= row || j < 0 || j >= col || grid[i][j] != 1) {
            return area;
        }
        grid[i][j] = 2;
        area+=1;
        area = getTotalArea(grid, i - 1, j, row, col, area);
        area = getTotalArea(grid, i + 1, j, row, col, area);
        area = getTotalArea(grid, i, j - 1, row, col, area);
        area = getTotalArea(grid, i, j + 1, row, col, area);
        return area;
    }
};
