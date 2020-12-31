/*
Leetcode - 256.
*/

#include<bits/stdc++.h>
using namespace std;

int min_cost_to_paint(int cost[][3]){
	if(cost==NULL){
		return 0;
	}
	for(int i=1;i<3;i++){
		cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
		cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
		cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
	}
	return min(min(cost[2][0], cost[2][1]), cost[2][2]);
}

int main(){
	int cost[][3]={{17, 2, 17}, 
					{16, 16, 5}, 
					{14, 3, 19}};
					
	cout<<min_cost_to_paint(cost);
	return 0;
}
