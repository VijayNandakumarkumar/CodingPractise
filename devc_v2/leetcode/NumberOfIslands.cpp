/******************************************************************************

                              Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int isSafe(vector<vector<int>> arr, int i, int j){
    return (i < 5) && (i >= 0) && (j< 5) && (j >= 0) && (arr[i][j] == 1);
}
void dfs(vector<vector<int>> &arr, int i, int j){
    arr[i][j]=2;
    vector<int> row{-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> col{-1, 0, 1, 1, -1, 1, 0, -1};
    for(int k =0;k<8;k++){
        if(isSafe(arr, i +row[k], j+col[k]))
            dfs(arr, i +row[k], j+col[k]);
    }
}
int findIslands(vector<vector<int>> &arr, int row, int col){
    int count  = 0;
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == 1){
                dfs(arr, i, j);
                count++;
            }
        }
    }
    return count;
    
}

int main()
{
    vector<vector<int>> arr{ { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };
    cout<<findIslands(arr, 5, 5);

    return 0;
}


