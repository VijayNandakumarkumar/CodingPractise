#include <bits/stdc++.h>

using namespace std;

int isSafe(vector<vector<string> >& board, int i, int j, int n, int m){
        if((i>=0)&&(i<n)&&(j>=0)&&(j<m)&&(board[i][j]=="X")){
            return 1;
        }
        return 0;
    }
    void dfs(vector<vector<string> >& board, int i, int j, int n, int m){
        board[i][j] = '.';
        vector<int> row;
		vector<int> col;
		
		row.push_back(0);
		row.push_back(1);
		
		col.push_back(1);
		col.push_back(0);
        
        if(isSafe(board, i+row[0], j+col[0], n, m)){
            dfs(board, i+row[0], j+col[0], n, m);
        }
        else if(isSafe(board, i+row[1], j+col[1], n, m)){
            dfs(board, i+row[1], j+col[1], n, m);
        }
    }
    int countBattleships(vector<vector<string> > &board) {
        
        int n = (int)board.size(), m = (int)board[0].size(), count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=="X"){
                    dfs(board, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
    
    int main(){

    	vector<vector<string> > v{ { "X",".",".","X"}, 
                     			   {".","X",".","X" }, 
                                   { ".","X",".","X" } };
		cout<<"Total ships  = "<<countBattleships(v);
	 	return 0;	
	}
