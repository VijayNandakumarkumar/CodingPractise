/**
1252. Cells with Odd Values in a Matrix

Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.

 

Example 1:


Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

*/

#include<bits/stdc++.h>

using namespace std;

int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> v (n, vector<int> (m, 0));
        map<int, int> r;
        map<int, int> c;
        int count = 0;
        for (int i = 0; i< indices.size(); i++) {
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }
        for(int i = 0;i<n;i++) {
            for (int j=0;j<m;j++) {
                v[i][j] = r[i] + c[j];
                if ((v[i][j]%2) != 0) {
                    count++;
                }
            }
        }
        return count;
    }

int main() {

	vector<vector<int>> v (2, vector<int> (2, 0));
	
	v[0][1] = 1;
	v[1][0] = 1;
	v[1][1] = 1;
	cout<<oddCells(2,3, v);
	
	return 0;
}
