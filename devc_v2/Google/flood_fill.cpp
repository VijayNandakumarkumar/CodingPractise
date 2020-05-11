#include<bits/stdc++.h>
using namespace std;

int a[][3]={{1,1,1},{1,1,0},{1,0,1}};

bool isSafe(int i, int j, int c1, int color){
	if((i<3)&&(i>=0)&&(j<3)&&(j>=0)&&(a[i][j]==c1)){
		a[i][j]=color;
		return true;
	}
	return false;
}

void flood_fill(int i, int j, int c1, int color){
	vector<int> row{-1, 0, 0, 1};
	vector<int> col{0, -1, 1, 0};
	for(int k=0;k<4;k++){
		if(isSafe(i+row[k], j+col[k], c1, color)){
			flood_fill(i+row[k], j+col[k], c1, color);
		}
	}
}

int main(){
	
	flood_fill(1, 1, a[1][1], 2);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}
