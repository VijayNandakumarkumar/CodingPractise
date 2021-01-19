/*

73. Set Matrix Zeroes

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/


void setZeroes(vector<vector<int>>& matrix) {
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        bool isCol = false;
        
        for (int i=0;i<m;i++) {
            if (matrix[i][0] == 0) {
            isCol = true;
        }
            for (int j=1;j<n;j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for(int i=0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        
        if (isCol) {
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }    
    }


