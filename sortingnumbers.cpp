#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=432501;
	int temp=a;
	for(int i=0;i<=9;i++)
	{//cout<<"for";
		temp=a;
		while(temp>0)
		{   //cout<<"\n while";
			int t=temp%10;
			if(t==i)
			{
			//	cout<<"\n if";
				cout<<t;
			}
			temp=temp/10;
		}
	}
return 0;
}
