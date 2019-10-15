#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=0,k=0,t=0;
	string s="1.0.12";
	char *q,*p;
	string word;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='.')
		{
			//strcat(q,s[i]);
			k = k*10 + ( s[i] - '0');
		}
	}cout<<k;
	long v = strtol(q , &p , 10);
	return 0;
}
