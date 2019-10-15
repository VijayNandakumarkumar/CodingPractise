#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10]={2,3,1,4,5,8,6,9,0,7};
	for(int i=0;i<10-1;i++)
	{
		for(int j=0;j<10-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	int i=0;
	while(i<10)
	cout<<a[i++];
return 0;
}
