/*

36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Algo Unchained

*/

// Solution-1 Optimal (O(n2) - time, O(n) - space)

bool isValidSudoku(vector<vector<char>>& board) {
        
        set<string> s;
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                
                if (board[i][j] == '.')
                    continue;
                
                string currChar = to_string(board[i][j]);  
                
                string rowVal = "(" + to_string(i) + ")" + currChar; // (row) val -> (03)
                string colVal = currChar + "(" + to_string(j) + ")"; // val(col) --> (30)
                string boxVal = "(" + to_string(i/3) + currChar + to_string(j/3) + ")"; // (row val col). -->>. (030)
                if ((s.find(rowVal) != s.end()) 
                || (s.find(colVal) != s.end())
                || (s.find(boxVal) != s.end())) {
                    return false;
                } else {
                    s.insert(rowVal);
                    s.insert(colVal);
                    s.insert(boxVal);
                }
            }
        }
        return true;
    }

// Solution-2 SubOptimal (O(n2) - time and space)

bool isValidSudoku(vector<vector<char>>& board) {
       vector<set<char>> rows (9);
        vector<set<char>> cols (9);
        vector<set<char>> boxes (9);
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                char currChar = board[i][j];
                if (currChar == '.')
                    continue;
                if ((rows[i].find(currChar) != rows[i].end()) 
                || (cols[j].find(currChar) != cols[j].end())
                || (boxes[(i/3)*3 + (j/3)].find(currChar) != boxes[(i/3)*3 + (j/3)].end())) {
                    return false;
                } else {
                    rows[i].insert(currChar);
                    cols[j].insert(currChar);
                    boxes[(i/3)*3 + (j/3)].insert(currChar);
                }
            }
        }
        return true; 
    }
