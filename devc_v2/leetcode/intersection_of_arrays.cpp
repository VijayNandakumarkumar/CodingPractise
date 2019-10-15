//#intersection of two arrays
//
//#sort the arrays
//
//#and compare each element one by one

#include<bits/stdc++.h>

using namespace std;

int main(){
	int a1[5] = {1,5,3,6,3}, a2[7]={1,6,4,3,2,3,5};
	
	int len1 = sizeof(a1)/sizeof(a1[0]), len2 = sizeof(a2)/sizeof(a2[0]);
	int *ret_arr = (int*)malloc(sizeof(int) * 2);
	int i=0, j=0;
	
	vector<int> v;
	vector<int>::iterator it;
	vector<int>::reverse_iterator ir;
	
	sort(a1, a1+len1);
	sort(a2, a2+len2);
	
	while(i<len1 && j<len2){
		if(a1[i] == a2[j]){
			v.push_back(a1[i]);
			i++, j++;
		}
		else if(a1[i]<a2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	
	for (ir = v.rbegin(); ir != v.rend(); ++ir) 
        cout << *ir << " "; 
	
	return 0; 	
 }
