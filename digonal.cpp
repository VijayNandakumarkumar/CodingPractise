// C++ implementation to find the maximum sum
// path in a matrix
#include <bits/stdc++.h>
using namespace std;
 
#define SIZE 10
 
// function to find the maximum sum
// path in a matric
int maxSum(int mat[SIZE][SIZE], int n)
{
    // if there is a single element only
    if (n == 1)
        return mat[0][0];
 
    // dp[][] matrix to store the results
    // of each iteration
    int dp[n][n];
    int maxSum = INT_MIN, max;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    {
    	dp[i][j]=0;
	}
	}
    // base case, copying elements of
    // last row
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = mat[n - 1][j];
 
    // building up the dp[][] matrix from
    // bottom to the top row
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            max = INT_MIN;
 
            // finding the maximum diagonal element in the
            // (i+1)th row if that cell exists
            if (((j + 1) >= 0) && (max < mat[i][j + 1]))
                max = mat[i][j + 1];
            if (((i + 1 )< n) && (max < mat[i + 1][j]))
                max = mat[i + 1][j];
 
            // adding that 'max' element to the
            // mat[i][j] element
            cout<<"max = "<<max<<"\n";
            dp[i][j] = mat[i][j] + max;
        }
    }
 
    // finding the maximum value from the
    // first row of dp[][]
    for (int j = 0; j < n; j++)
        if (maxSum < dp[0][j])
            maxSum = dp[0][j];
 
    // required maximum sum
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    {cout<<dp[i][j]<<"\t";
	}cout<<"\n";}
    return maxSum;
}
 
// Driver program to test above
int main()
{
    int mat[SIZE][SIZE] = { { 5, 6, 1, 7 },
                            { -2, 10, 8, -1 },
                            { 3, -7, -9, 11 },
                            { 12, -4, 2, 6 } };
    int n = 4;
 
    cout << "Maximum Sum = "
         << maxSum(mat, n);
 
    return 0;
}

