#include<bits/stdc++.h>
using namespace std;
int main()
{	string b="hello hi ",word="";
	int len = b.size(),k=0;
	string a[3];
	for(int i=0;i<len;i++)
	{
		if(b[i]!=' ')
		{
			word=word+b[i];
			//cout<<word;
		}
		else{
			cout<<word;
		a[k++] = word;
		word = " ";
	}
	}
	for(int j=k-1;j>=0;j--)
	cout<<a[j]<<" ";
	return 0;
}
