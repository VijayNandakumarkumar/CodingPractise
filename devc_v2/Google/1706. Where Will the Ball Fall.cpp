/*

1706. Where Will the Ball Fall

You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

    A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
    A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.

We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

 

Example 1:

Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.

Example 2:

Input: grid = [[-1]]
Output: [-1]
Explanation: The ball gets stuck against the left wall.

Example 3:

Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
Output: [0,1,2,3,4,-1]


*/

class Solution {
public:

    //Our Solution, below is same but little simplified code.
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if ((m==1 && n==1) || (n==1)) {
            return {-1};
        }
        vector<int> ans (n, 0);
        
        for (int j=0; j<n; j++) {
            ans[j] = getBallFall(0, j, ans, grid, m, n);
        }
        return ans;
    }
    
    int getBallFall(int i, int j, vector<int> &ans, vector<vector<int>>& grid, int m, int n) {
        
        if (i==m) {
            return j;
        }
        if (j==0) { 
            if (grid[i][j]==-1 || n==1) {
                return -1;
            }
        } else if (j==n-1) {
            if (grid[i][j]==1 || n==1) {
                return -1;
            }
        }
        if (i>=0 && i<m) {
            if (grid[i][j] == 1) {
                if (grid[i][j+1] == 1) {
                    return getBallFall(i+1, j+1, ans, grid, m, n);
                }
                return -1;
            } else {
                if (grid[i][j-1]==-1) {
                    return getBallFall(i+1, j-1, ans, grid, m, n);
                }
                return -1;
            }
        }
        
        return -1;
    }

    class Solution {
public:
    /*
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if ((m==1 && n==1) || (n==1)) {
            return {-1};
        }
        vector<int> ans (n, 0);
        
        for (int j=0; j<n; j++) {
            ans[j] = getBallFall(0, j, ans, grid, m, n);
        }
        return ans;
    }
    
    int getBallFall(int i, int j, vector<int> &ans, vector<vector<int>>& grid, int m, int n) {
        
        if (i==m) {
            return j;
        }
        if (j==0) { 
            if (grid[i][j]==-1 || n==1) {
                return -1;
            }
        } else if (j==n-1) {
            if (grid[i][j]==1 || n==1) {
                return -1;
            }
        }
        if (i>=0 && i<m) {
            if (grid[i][j] == 1) {
                if (grid[i][j+1] == 1) {
                    return getBallFall(i+1, j+1, ans, grid, m, n);
                }
                return -1;
            } else {
                if (grid[i][j-1]==-1) {
                    return getBallFall(i+1, j-1, ans, grid, m, n);
                }
                return -1;
            }
        }
        
        return -1;
    }
    */
    
    
    int n,m;
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> result(m);
        for(int i = 0; i < m; i++)
            result[i] = helper(grid, 0, i);
        return result;
    }
    int helper(vector<vector<int>>& grid, int i, int j){
        if(i == n)
            return j;
        if(grid[i][j] == 1 && (j == m - 1 || grid[i][j + 1] == -1) || grid[i][j] == -1 && (j == 0 || grid[i][j - 1] == 1))
            return -1;
        return helper(grid, i + 1, j + grid[i][j]);
    }
    
    /*
    int n,m;
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> result(m);
        vector<vector<int>> memo(n, vector<int>(m, -2));
        for(int i = 0; i < m; i++)
            result[i] = helper(memo, grid, 0, i);
        return result;
    }
    int helper(vector<vector<int>>& memo, vector<vector<int>>& grid, int i, int j){
        if(i == n)
            return j;
        if(memo[i][j] != -2)
            return memo[i][j];
        if(grid[i][j] == 1 && (j == m - 1 || grid[i][j + 1] == -1) || grid[i][j] == -1 && (j == 0 || grid[i][j - 1] == 1))
            return memo[i][j] = -1;
        return memo[i][j] = helper(memo, grid, i + 1, j + grid[i][j]);
    }*/
};
};