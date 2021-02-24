/*

52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

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
    
    int totalNQueens(int n) {
        vector<Nde> v (n);
        int result = 0;
        placeQueens(n, 0, result, v);
        return result;
    }
    
    void placeQueens(int n, int row, int &result, vector<Nde> &v) {
        if (n == row) {
            result++;
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
