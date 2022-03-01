/*

562. Longest Line of Consecutive One in Matrix

Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.

 

Example 1:

Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 3


*/

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxLen = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 1) {
                    int len = getLength(i, j, mat, m, n);
                    if (len> maxLen) {
                        maxLen = len;
                    }
                }
            }
        }
        return maxLen;
    }
    
    int getLength(int i, int j, vector<vector<int>>& a, int m, int n) {
        int maxLen=0;
        int count = 0;
        if (i>0 && (a[i-1][j]==1)) {
        } else {
            count=0;
            for (int c=i; c<m; c++) {
                if (a[c][j]!=1) {
                   break;
                }
                count++; 
            }
            maxLen = (count>maxLen) ? count : maxLen;
            count=0;
        }
        if (j>0 && (a[i][j-1]==1)) {
            
        } else {
            for (int c=j; c<n; c++) {
                if (a[i][c]!=1) {
                   break;
                }
                count++; 
            }
            maxLen = (count>maxLen) ? count : maxLen;
            count=0;
        }
        if (i>0 && j>0 && (a[i-1][j-1]==1)) {
            
        } else {
            for (int c=i, d=j; c<m && d<n; c++, d++) {
                if (a[c][d]!=1) {
                   break;
                }
                count++; 
            }
            maxLen = (count>maxLen) ? count : maxLen;
            count=0;
        }
        
        if (i>0 && j>0 && j<(n-1) && (a[i-1][j+1]==1)) {
            
        } else {
            for (int c=i, d=j; c<m && d>=0; c++, d--) {
                if (a[c][d]!=1) {
                   break;
                }
                count++; 
            }
            maxLen = (count>maxLen) ? count : maxLen;
            count=0;
        }
        cout<<"Max4 = "<<maxLen<<endl;
        return maxLen;
    }
};