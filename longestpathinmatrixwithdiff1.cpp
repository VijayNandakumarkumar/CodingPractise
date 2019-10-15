#include<bits/stdc++.h>
using namespace std;
#define n 3
int findlongestoverall(int mat[][n]);
int findlongestfromacell(int i, int j, int mat[][n], int dp[][n]);
int main()
{
	int  mat[n][n] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
	cout<<findlongestoverall(mat)<<"\n";
	return 0;
}
int findlongestoverall(int mat[][n])
{	int result = 1;  // Initialize result
 
    // Create a lookup table and fill all entries in it as -1
    int dp[n][n];
    memset(dp, -1, sizeof dp);
 
    // Compute longest path beginning from all cells
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
       {
          if (dp[i][j] == -1)
             findlongestfromacell(i, j, mat, dp);
 
          //  Update result if needed
          result = max(result, dp[i][j]);
       }
     }
 
     return result;
}
int findlongestfromacell(int i, int j, int mat[][n], int dp[][n])
{
	if (i<0 || i>=n || j<0 || j>=n)
        return 0;
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if((j<n-1)&&(mat[i][j]+1 == mat[i][j+1]))
	return dp[i][j] = 1 + findlongestfromacell(i, j+1, mat, dp);
	if((j>0)&&(mat[i][j]+1 == mat[i][j-1]))
	return dp[i][j] = 1 + findlongestfromacell(i, j-1, mat, dp);
	if((i>0)&&(mat[i][j]+1 == mat[i-1][j]))
	return dp[i][j] = 1 + findlongestfromacell(i-1, j, mat, dp);
	if((i<n-1)&&(mat[i][j]+1 == mat[i+1][j]))
	return dp[i][j] = 1 + findlongestfromacell(i+1, j, mat, dp);
	return dp[i][j]=1;
	/*	if (dp[i][j] != -1)
        return dp[i][j];
 
    // Since all numbers are unique and in range from 1 to n*n,
    // there is atmost one possible direction from any cell
   if (j<n-1 && ((mat[i][j] +1) == mat[i][j+1]))
       return dp[i][j] = 1 + findlongestfromacell(i,j+1,mat,dp);
 
    if (j>0 && (mat[i][j] +1 == mat[i][j-1]))
       return dp[i][j] = 1 + findlongestfromacell(i,j-1,mat,dp);
 
    if (i>0 && (mat[i][j] +1 == mat[i-1][j]))
       return dp[i][j] = 1 + findlongestfromacell(i-1,j,mat,dp);
 
    if (i<n-1 && (mat[i][j] +1 == mat[i+1][j]))
       return dp[i][j] = 1 + findlongestfromacell(i+1,j,mat,dp);
 
    // If none of the adjacent fours is one greater
    return dp[i][j] = 1;
*/}
