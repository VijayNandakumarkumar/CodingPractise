#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> a;
	a.push_back(9);
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	a.push_back(7);
	a.push_back(2);
	a.push_back(1);
	
	vector<int>::iterator itr;
	
	for(itr =a.begin();itr!=a.end();itr++){
		cout<<*itr<<"\t";
	}
	int i=0;
	int hole = 0, value_to_insert = 0;
	for(i=1;i<(int)a.size();i++){
		cout<<"I = "<<i<<"\n";
		hole = i;
		value_to_insert = a[hole];
		cout<<a[hole]<<"\t"<<a[1]<<"\t"<<a[0]<<"\n";
		while((hole>0)&&(a[hole-1]>value_to_insert)){
			cout<<"Came here"<<a[hole - 1]<<"\t"<<a[hole]<<"\n";
			a[hole] = a[hole-1];
			--hole;
		}
		
		if(hole!=i){
			a[hole] = value_to_insert;
		}
	}
	cout<<"\n";
	for(itr =a.begin();itr!=a.end();itr++){
		cout<<*itr<<"\t";
	}
	
	return 0;
}
