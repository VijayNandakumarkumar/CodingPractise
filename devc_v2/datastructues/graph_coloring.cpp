#include<bits/stdc++.h>
using namespace std;

#define N 4

bool isSafe(int v, int g[N][N], vector<int> &color, int c){
	for(int i=0;i<N;i++){
		if((g[v][i])&&(color[i]==c)){
			return false;
		}
	}
	return true;
}


bool graphColorUtil(int g[N][N], vector<int> &color, int v, int m){
	if(v==N){
		return true;
	}
	for(int c=1;c<=m;c++){
		if(isSafe(v, g, color, c)){
			
			color[v]=c;
			if(graphColorUtil(g, color, v+1, m)==true){
				return true;
			}
			color[v]=0;
		}
	}
	return false;
}

void printSolution(vector<int> &color){
	for(int i=0;i<N;i++){
		cout<<"color of "<<i<<"is "<<color[i]<<"\n";
	}
}

bool graphColoring(int g[N][N], int m){
	vector<int> color{0};
	if(graphColorUtil(g, color, 0, m)==false)
	{
		return false;
	}
	printSolution(color);
	return true;
}



int main(){
	int g[4][4] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m=3;
    graphColoring(g, m);
	
	return 0;
}
