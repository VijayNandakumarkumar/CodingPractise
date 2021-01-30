/*

463. Island Perimeter.

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4

*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i =0;i<row;i++) {
            for (int j = 0;j<col;j++) {
                if (grid[i][j] == 1) {
                    return getTotalArea(grid, i, j, row, col, 0);
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
        area+=4;
        if (i > 0 && grid[i-1][j] != 0) {
            area -= 1;
        } 
        if (j > 0 && grid[i][j-1] != 0) {
            area -= 1;
        } 
        if (j < col - 1 && grid[i][j + 1] != 0) {
            area -= 1;
        }
        if (i < row - 1 && grid[i + 1][j] != 0) {
            area -= 1;
        }
        
        area = getTotalArea(grid, i - 1, j, row, col, area);
        area = getTotalArea(grid, i + 1, j, row, col, area);
        area = getTotalArea(grid, i, j - 1, row, col, area);
        area = getTotalArea(grid, i, j + 1, row, col, area);
        return area;
    }
    
};



    
