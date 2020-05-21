/**
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
 0 0 0 1
 0 1 1 0

 0 1 1 0

 1 0 1 1
 
 ===4
*/

#include<bits/stdc++.h>
using namespace std;

void display_matrix(vector<vector<int> > &v) {
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<v[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int longest_length_of_consecutive_ones(vector<vector<int> > &v) {
	int ones = 0;
	int row = 4, col = 4;
	int i=0,j=0;
	int count = 0;
	for(int i=0;i<row;i++){
		count = 0;
		for(int j=0;j<col;j++){
			if(v[i][j] == 1) {
				count = 1;
				if ((j>0) && (v[i][j-1] != 1)) {
					int c = j + 1;
					while ((c<col) && (v[i][c] == 1)) {
						count++;
						c++;
					}
				}
				ones = max(ones, count);
				count = 1;
				cout<<"\n";
				if ((i>0) && (v[i-1][j] == 1)) {
				} else {
					int c = i + 1;
					while ((c<row) && (v[c][j] == 1)) {
						count++;
						c++;
					}
				}
				ones = max(ones, count);
				count = 1;
				
				if ((i>0) && (j>0) && (v[i-1][j-1] == 1)){
				} else {
					int c = i + 1, d = j +1;
					while((c<row) && (d<col) && (v[c][d] == 1)) {
						count++;
						c++;
						d++;
					}
				}
				ones = max(ones, count);
				count = 1;
				
				if ((i>0) && (j>0) && (j<col-1) && (v[i-1][j+1] == 1)){
					
				} else {
					int c = i +1, d = j-1;
					while((c<row) && (d>=0) && (v[c][d] == 1)) {
						count++;
						c++;
						d--;
					}
				}
				ones = max(ones, count);
				count = 1;
			}
		}
	}
	
	return ones;
}

int main(){
	vector<vector<int> > v(4, vector<int> (4, 0));
	v[0][3] = 1;
	v[1][1] = 1;
	v[1][2]  = 1;
	v[2][1] = 1;
	v[2][2] = 1;
	v[3][2] = 1;
	v[3][3] = 1;
	v[3][0] = 1;
	display_matrix(v);
	
	cout<<longest_length_of_consecutive_ones(v);
	return 0; 
}
