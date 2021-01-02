/*

Leetcode: 266.

*/


//Approach 1: Simple and will work for all cases.

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "abb";
    vector<int> v(128, 0);
    vector<int>::iterator it;
    for(int i = 0;i<s.length();i++) {
        v[s[i]]++;
    }
    int count = 0;
    for(it = v.begin();it!=v.end();it++) {
        count += *it % 2;
    }
	cout<<(count<=1);
	return 0;
}


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
