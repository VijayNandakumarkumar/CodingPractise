#include<bits/stdc++.h>

using namespace std;

int main(){
	int c[128];
	string s = "omommmnp";
	int i=0;
	int count = 0;
	for(i=0;i<128;i++){
		c[i]=0;
	}
	for(i=0;i<s.length();i++){
		c[s[i]]++;
		if((c[s[i]]%2)==0){
			count--;
		}
		else{
//			cout<<"CAme here "<<s[i]<<" "<<c[s[i]];
			count++;
		}
	}
	if(((s.length())%2)==0)
	{
		cout<<(count == 0);
	}
	else{
		cout<<(count == 1);
	}
	
	return 0;
}
