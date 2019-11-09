		/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> spiral(vector<vector<int>> &mat, int m, int n){
    vector<int> arr;
    int k = 0, l = 0, i = 0;
    while(k<m&&l<n){
        for(i=k;i<n;i++){
            arr.push_back(mat[k][i]);
        }
        k++;
        for(i=k;i<m;i++){
            arr.push_back(mat[i][n-1]);
        }
        n--;
        if(k<m){
            for(i=n-1;i>=l;i--){
                cout<<mat[m-1][i]<<"\n";
                arr.push_back(mat[m-1][i]);
            }
            m--;
        }
        if(l<n){
            for(i=m-1;i>=k;i--){
                cout<<mat[i][l]<<"\n";
                arr.push_back(mat[i][l]);
            }
            l++;
        }
    }
    
    for(i=0;i<arr.size();i++){
        cout<<arr[i];
    }
}

int main()
{
    // 1 2 3
    // 4 5 6
    // 7 8 9
    vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    spiral(arr, 3, 3);

    return 0;
}
