/*

79. Word Search

Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

*/

bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int index = 0;
        for (int i = 0;i < row; i++) {
            for (int j = 0;j < col; j++) {
                if ((board[i][j] == word[index]) && dfs(board, word, i, j, index, row, col)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& s, string word, int i, int j, int index, int row, int col) {
        if (index == word.length()) {
            return true;
        }
        if (i<0 || i>= row || j< 0 || j>=col || s[i][j] != word[index]) {
            return false;
        }
        char temp = s[i][j];
        s[i][j] = ' ';
        bool found = dfs(s, word, i - 1, j, index + 1, row, col) 
            || dfs(s, word, i, j-1, index + 1, row, col)
            || dfs(s, word, i + 1, j, index + 1, row, col)
            || dfs(s, word, i, j+1, index + 1, row, col);
        s[i][j] = temp;
        return found;
    }
