
/*

Leetcode: 246.

*/

#include<bits/stdc++.h>
using namespace std;

bool is_strobogrammatic_number(string s, int n){
	for(int i=0;i<n;i++){
		switch(s[i]-48){
			case 2:
			case 3:
			case 4:
			case 5:
			case 7: return false;
			case 6: 
				{
				if('9'!=s[n-1-i])
					return false;
				}
				break;
			case 9: if('6'!=s[n-1-i])return false;break;
			case 8:
			case 0:
			case 1: if(s[i]!=s[n-1-i]) return false;break;
		}
	}
	return true;
}

int main(){
//	string s = "69";
//	string s = "88";
	string s = "818";
//	string s = "72";
	int n=s.length();
	cout<<is_strobogrammatic_number(s, n);
	return 0;
}
