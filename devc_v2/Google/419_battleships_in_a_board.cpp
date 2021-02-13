/*

419. Battleships in a Board

Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

*/

// Solution-1 (Onm and O(1))

 
    int countBattleships(vector<vector<char>>& board) {
        if((int)board.size()==0)
            return -1;
        int m = (int)board.size(), n = (int)board[0].size(), count = 0;
        int ships = 0;
        for (int i =0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if ((j>0) && (board[i][j-1] == 'X')) {
                    
                } else if ((i>0) && (board[i - 1][j] == 'X')) {
                
                } else {
                    ships++;
                }
            }
        }
        return ships;
    }

// Solution-2: DFS

int isSafe(vector<vector<char>>& board, int i, int j, int n, int m){
        if((i>=0)&&(i<n)&&(j>=0)&&(j<m)&&(board[i][j]=='X')){
            return 1;
        }
        return 0;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        cout<<" i= "<<i<<" j= "<<j<<"\n";
        board[i][j] = '.';
        vector<int> row{0, 1};
        vector<int> col{1, 0};
        for(int k=0;k<2;k++){
            if(isSafe(board, i+row[k], j+col[k], n, m)){
                dfs(board, i+row[k], j+col[k], n, m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        if((int)board.size()==0)
            return -1;
        int n = (int)board.size(), m = (int)board[0].size(), count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(board, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
