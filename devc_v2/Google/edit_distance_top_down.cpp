#include<bits/stdc++.h>
using namespace std;

int edit_distance(string s1, string s2, int a[][7]){
	
	if(s1.length()==0){
		cout<<"S1 Came here";
		return s2.length()+1;
	}
	if(s2.length()==0){
		cout<<"S2 Came here";
		return s1.length()+1;
	}
	else{
		for(int i=1;i<7;i++){
			for(int j=1;j<7;j++){
				if(s1[i-1]==s2[j-1]){
					a[i][j]=a[i-1][j-1];
				}
				else{
					a[i][j]=1+min(a[i-1][j-1], min(a[i-1][j], a[i][j-1]));
				}
			}
		}
	}
	return a[s1.length()][s2.length()];
}

int main(){
	string s1 = "benyam", s2 =  "ephrem";
	int s1_len = s1.length(), s2_len=s2.length();
	int a[7][7];
	
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
		a[i][j]=-1;
		}
	}
	for(int i=0;i<7;i++){
		a[0][i]=i;
		a[i][0]=i;
	}
	
	
	cout<<edit_distance(s1, s2, a);
	cout<<"\n";
	return 0;
}
