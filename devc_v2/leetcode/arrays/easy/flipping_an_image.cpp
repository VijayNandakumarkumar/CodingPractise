/**
832. Flipping an Image

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int k = 0;
        for(int i=0; i<A.size(); i++) {
            for(int j=0, k=A[0].size() - 1;j <=k;j++, k--){
                int temp = A[i][j];
                A[i][j] = !(A[i][k]);
                A[i][k] = !temp;
            }
        }
        
        return A;
    }
    
void display(vector<vector <int>> &v) {
	for(int i = 0;i<v.size();i++) {
		for(int j=0;j<v.size();j++) {
			cout<<v[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
    
int main() {
	vector<vector<int>> v {{1,1,0}, {1,0,1}, {0,0,0}};
	display(v);
	flipAndInvertImage(v);
	display(v);
	return 0;
}
