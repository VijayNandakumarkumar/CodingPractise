#include<bits/stdc++.h>
using namespace std;

#define N 4

bool adj[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 

bool knows(int a, int b){
	return adj[a][b];
}

int find_celebrity(){
	stack<int> s;
	int i=0;
	for(i=0;i<N;i++){
		s.push(i);
	}
	int a=0;
	int b=0, c=0;
	while(s.size()>1){
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		if(knows(a, b)){
			s.push(b);
		}
		else{
			s.push(a);
		}
	}
	c=s.top();
	for(i=0;i<N;i++){
		if((i!=c)&&(!adj[i][c])){
			return -1;
		}
	}
	return c;
}

int main(){
	cout<<find_celebrity();
	return 0;
}
