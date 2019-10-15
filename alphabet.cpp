#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
	if(n>0)
	{
		n--;
		print(n/26);
		printf("%c\t%d",(n%26)+65,n);
	}
}
int main()
{
	int n;
	cin>>n;
	print(n);
	return 0;
}
