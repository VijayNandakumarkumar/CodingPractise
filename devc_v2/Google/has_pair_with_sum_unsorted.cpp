#include<bits/stdc++.h>

using namespace std;

bool hasPairWithSum(vector<int> &data, int sum){
	vector<int> comp;
	vector<int>::iterator i;
	for(int val: data){
		i = find(comp.begin(), comp.end(), val);
		if(i!=comp.end()){
			return true;
		}
		comp.push_back(sum-val);
	}
	return false;
}


int main(){
	vector<int> v{1, 4, 4, 2};
	cout<<hasPairWithSum(v, 8);
	
	return 0;
}

