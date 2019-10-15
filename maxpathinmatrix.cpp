#include<bits/stdc++.h>
using namespace std;
#define N 3
int findmax(int mat[][N]);
int main()
{
	int mat[N][N]={{1,2,3},{9,8,7},{4,5,6,}};
	cout<<findmax(mat)<<"\n";
	return 0;
}
int findmax(int mat[][N])
{
	for(int i=0;i<N;i++)
{	for(int j=0;j<N;j++)
	cout<<mat[i][j]<<"\t";
	cout<<"\n\n";
}	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if((j>0)&&(j<N-1))
			{
				mat[i][j]+=max(mat[i-1][j],max(mat[i-1][j-1],mat[i-1][j+1]));
			}
			else if(j>0)
			{
				mat[i][j]+=max(mat[i-1][j],mat[i-1][j-1]);
			}
			else if(j<N-1)
			{
				mat[i][j]+=max(mat[i-1][j],mat[i-1][j+1]);
			}
		}
	}
	for(int i=0;i<N;i++)
{	for(int j=0;j<N;j++)
	cout<<mat[i][j]<<"\t";
	cout<<"\n";
}	int res = 0;
	for(int j=0;j<N;j++)
	{
		if(res<mat[N-1][j])
		{
			res=mat[N-1][j];
		}
	}
}
