
/*

Check own implementation in algo and data structures.

*/

#include<bits/stdc++.h>
using namespace std;

int  knap_sack(int w, vector<int> &vt, vector<int> &wt, int n){
	if(n==0||w==0){
		return 0;
	}
	if(wt[n-1]>w){
		return knap_sack(w, vt, wt, n-1);
	}
	else{
		return max(vt[n-1]+knap_sack(w-wt[n-1], vt, wt, n-1), knap_sack(w, vt, wt, n-1));
	}
}

int main(){
	vector<int> vt{60, 100, 120};
	vector<int> wt{10, 20, 30};
	int W = 50;
	cout<<knap_sack(W, vt, wt, 3);
	return 0;
}
