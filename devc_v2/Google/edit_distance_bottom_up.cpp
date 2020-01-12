#include <bits/stdc++.h>
using namespace std;
int edit_distance(string s1, int s1_len, string s2, int s2_len, int a[][6]){
	if(s1_len<0){
		return s2_len+1;
	}
	if(s2_len<0){
		return s1_len+1;
	}
	if(a[s1_len][s2_len]!=-1){
		return a[s1_len][s2_len];
	}
	if(s1[s1_len]==s2[s2_len]){
		a[s1_len][s2_len] =  edit_distance(s1, s1_len-1, s2, s2_len-1, a);
	}
	
	else{
		int del=edit_distance(s1, s1_len-1, s2, s2_len, a);
		int ins=edit_distance(s1, s1_len, s2, s2_len-1, a);
		int substitute=edit_distance(s1, s1_len-1, s2, s2_len-1, a);
		a[s1_len][s2_len] = 1+ min(del, min(ins, substitute));
	}
	
	return a[s1_len][s2_len];
}

int main(){
	string s1 = "benyam", s2 =  "ephrem";
	int s1_len = s1.length(), s2_len=s2.length();
	int a[6][6];
	
	for(int i=0;i<s1_len;i++){
		for(int j=0;j<s2_len;j++){
		a[i][j]=-1;
		}
	}
	cout<<edit_distance(s1, s1_len-1, s2, s2_len-1, a);
	
;	return 0;
}
