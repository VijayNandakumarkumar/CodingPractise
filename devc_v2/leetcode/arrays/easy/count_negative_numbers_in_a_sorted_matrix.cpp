/**
1351. Count Negative Numbers in a Sorted Matrix

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
*/

#include<bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=grid.size()-1;i >= 0; i--) {
            for (int j=grid[0].size()-1;j >= 0; j--) {
                if (grid[i][j] >= 0) {
                    break;
                } else {
                    count++;
                }
        }
    }
        return count;
    }

int main() {
	vector< vector<int>> v {{4,3,2,-1}, {3,2,1,-1},{1,1,-1,-2}, {-1,-1,-2,-3}};
	cout<<countNegatives(v);
	
	return 0;
}
