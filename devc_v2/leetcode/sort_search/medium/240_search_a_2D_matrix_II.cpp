/*

240. Search a 2D Matrix II

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true


*/

Solution 1: O(m+n)

bool searchMatrix(vector<vector<int>>& v, int target) {
        if (v.size() == 0)
            return false;
        int row = 0;
        int col = v[0].size() - 1;
        while(row < v.size() && col >= 0) {
            if (v[row][col] == target) {
                return true;
            } else if (v[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }

Solution 2: O(n*m)

bool searchMatrix(vector<vector<int>>& v, int target) {
        vector<int> row;
        vector<int> col;
        int m = v.size();
        int n = v[0].size();
        for(int i = 0;i<m;i++) {
            if (v[i][0] <= target && v[i][n-1] >= target) {
                row.push_back(i);
            }
        }
        for(int i = 0;i<n;i++) {
            if (v[0][i] <= target && v[m-1][i] >= target) {
                col.push_back(i);
            }
        }
        if (row.size() == 0 && col.size() == 0) {
            return false;
        }
        cout<<m<<" "<<n<<"\n"<<row.size()<<" "<<col.size();
        
    
        for (int i = 0;i< row.size();i++){
            for (int j = 0;j<col.size();j++) {
                // cout<<"i = "<<i<<" j = "<<j<<"\n";
                if (v[row[i]][col[j]] == target)
                    return true;
            }
        }
        return false;
    }
