/*

1222. Queens That Can Attack the King

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.

Example 1:

Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:  
The queen at [0,1] can attack the king cause they're in the same row. 
The queen at [1,0] can attack the king cause they're in the same column. 
The queen at [3,3] can attack the king cause they're in the same diagnal. 
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.

*/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        int krow = king[0];
        int kcol = king[1];
        vector<vector<int>> attackers (8);
        for(int i = 0; i<queens.size(); i++) {
            int row = queens[i][0];
            int col = queens[i][1];
            if((row == krow) || (kcol == col) || (row - col == krow - kcol) || (row+col == krow+kcol)) {
                if (row < krow) {
                    if (col < kcol) {
                        if ((attackers[0].size() == 0) 
                            || ((attackers[0][0] < row))) {
                            cout<<"Attacker 0 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[0] = queens[i];
                        }
                    } else if (col == kcol) {
                        if ((attackers[1].size() == 0) 
                            || ((attackers[1][0] < row))) {
                            cout<<"Attacker 1 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[1] = queens[i];
                        }
                    } else if (col > kcol) {
                        if ((attackers[2].size() == 0) 
                            || ((attackers[2][0] < row))) {
                            cout<<"Attacker 2 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[2] = queens[i];
                        }
                    }
                } 
                else if (row == krow) {
                    if (col < kcol) {
                        if ((attackers[3].size() == 0) 
                            || ((attackers[3][1] < col))) {
                            cout<<"Attacker 3 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[3] = queens[i];
                        }
                    } else if (col > kcol) {
                        if ((attackers[4].size() == 0) 
                            || ((attackers[4][1] > col))) {
                            cout<<"Attacker 4 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[4] = queens[i];
                        }
                    }
                } 
                else if (row > krow) {
                    if (col < kcol) {
                        if ((attackers[5].size() == 0) 
                            || ((attackers[5][0] > row))) {
                            cout<<"Attacker 5 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[5] = queens[i];
                        }
                    } 
                    else if (col == kcol) {
                        if ((attackers[6].size() == 0) 
                            || ((attackers[6][0] > row))) {
                            cout<<"Attacker 6 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[6] = queens[i];
                        }
                    } 
                    else if (col > kcol) {
                        if ((attackers[7].size() == 0) 
                            || ((attackers[7][0] > row))) {
                            cout<<"Attacker 7 "<<queens[i][0]<<" "<<queens[i][1]<<"\n";
                            attackers[7] = queens[i];
                        }
                    }
                }
            }
        }
        for(int i = 0;i<8;i++) {
                    if (attackers[i].size() != 0)
                        result.push_back(attackers[i]);
                }
        return result;
    }
};
