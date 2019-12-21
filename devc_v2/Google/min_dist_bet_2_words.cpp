#include<bits/stdc++.h>

using namespace std;

int mini(int min, int min2){
	if(min<min2)
		return min;
	return min2;
}

int main(){
	string s = "coding";
	string s1= "makes";
	vector<string> v;
	v.push_back("practice");
	v.push_back("makes");
	v.push_back("perfect");
	v.push_back("coding");
	v.push_back("makes");
	int i=0;
	int i1=0, i2=0, min = (int)v.size();
	for(i=0;i<(int)v.size();i++){
	if(v[i].compare(s)==0){
			i1=i+1;
		}
		else if(v[i].compare(s1)==0){
			i2=i+1;
		}
		if((i1!=0)&&(i2!=0)){
			min = mini(min, abs(i1 - i2));
		}
	}
	cout<<min;
	return 0;
}
