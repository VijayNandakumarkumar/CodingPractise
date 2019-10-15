#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a = "12345";
	string b = a;
	int len = a.size(),k=0,l=len-1;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(i==j)
			{
				cout<<a[k++];
				if(j==(len-i-1))
				l--;
				
			}
			else if(j==(len-i-1)&&(i!=j))
			{
				cout<<a[l--];
			}
			else
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
	}
