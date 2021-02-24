/*

51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

*/


class Solution {
public:
    
    struct Node {
        int row;
        int col;
        int hill;
        int dale;
    };
    
    typedef struct Node* Nde;
    
    Nde new_node(int row, int col) {
        Nde n = (Nde)malloc(sizeof(struct Node));
        n->row = row;
        n->col = col;
        n->hill = row - col;
        n->dale = row + col;
        return n;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<Nde> v (n);
        vector<vector<string>> result;
        placeQueens(n, 0, result, v);
        return result;
    }
    
    void placeQueens(int n, int row, vector<vector<string>> &result, vector<Nde> &v) {
        if (n == row) {
            vector<string> sol;
            for (int i = 0; i<v.size(); i++)
            {
                Nde queen = v[i];
                string s;
                for (int j = 0; j<n; j++) {
                    if (j != queen->col)
                        s += '.';
                    else
                        s += 'Q';
                }
                sol.push_back(s);
            }
            result.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) { //columns
            bool hasPlace = true;
            
            for (int q=0; q<row; q++) {
                Nde prevQueen = v[q];
                if (prevQueen != NULL) {
                    if ((prevQueen->col == i) 
                        || (prevQueen->hill == (row - i)) 
                        || (prevQueen->dale == (row + i))) {
                        hasPlace = false;
                        break;
                    }
                }
            }
            if (hasPlace) {
                // cout<<" row "<<row<<" col "<<i<<"\n";
                v[row] = new_node(row, i);
                placeQueens(n, row+1, result, v);
            }
        }

    }
};
