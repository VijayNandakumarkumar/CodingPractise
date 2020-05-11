#include<bits/stdc++.h>
using namespace std;
int graph[][4]{{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
int tsp(int s){
	vector<int> v;
	for(int i=0;i<4;i++){
		if(i!=s){
			v.push_back(i);
		}
	}
	int k=s;
	int min_path = INT_MAX;
	do{
		int current_path_weight=0;
		for(int i=0;i<v.size();i++){
			current_path_weight+=graph[k][v[i]];
			k=v[i];
		}
		current_path_weight += graph[k][s];
		cout<<"min path "<<min_path<<"\n";
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<"\t";
		}
		min_path=min(min_path, current_path_weight);
	}while(next_permutation(v.begin(), v.end()));
	return min_path;
}

int main(){
	cout<<tsp(0);
	return 0;
}
