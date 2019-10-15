#include<bits/stdc++.h>
using namespace std;
int a[4][4]={ {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}  };;
void print()
{
	for(int i=0;i<4;i++)
	{for(int j=0;j<4;j++)
	{
	
		cout<<a[i][j]<<'\t';
	}
	cout<<endl;
	}
}
void rotate(int mm, int nn, int a[4][4],int g)
{
	int row=0,col=0;
	int prev,curr,m,n;
	for(int l=0;l<g;l++){
	int row=0,col=0;
	int prev,curr,m=mm,n=nn;
	while(row<m&&col<n)
	{int i=0;
		if((row+1)==m||(col+1)==n)
	    break;
	    prev=a[row+1][col];
	    for(i=col;i<n;i++)
	    {
	    	curr=a[row][i];
	    	a[row][i]=prev;
	    	prev=curr;
		}
		row++;
		for(i=row;i<m;i++)
	    {
	    	curr=a[i][n-1];
	    	a[i][n-1]=prev;
	    	prev=curr;
		}
		n--;
		if(row<m)
		{
		for(i=n-1;i>=col;i--)
	    {
	    	curr=a[m-1][i];
	    	a[m-1][i]=prev;
	    	prev=curr;
		}
		m--;
	}
		if(col<n)
		{
			for(i=m-1;i>=row;i--)
	    {
	    	curr=a[i][col];
	    	a[i][col]=prev;
	    	prev=curr;
		}
		col++;
		
		}
	}
	}
	print();
}
int main()
{cout<<"before rotating"<<endl;
print();
cout<<"\ndeg";
int g;
cin>>g;
	rotate(4,4,a,g);
cout<<"after rotate"<<endl;
	return 0;
}

