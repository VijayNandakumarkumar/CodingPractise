/*

994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
    vector<string> fresh;
    
    vector<string> rotten;
    for (int i = 0;i< (int)grid.size(); i++) {
        for (int j = 0;j< (int)grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                fresh.push_back("" + to_string(i) + to_string(j));
            } else if (grid[i][j] == 2) {
                rotten.push_back("" + to_string(i) + to_string(j));
            }
        }
    }
        vector<int> row {0, -1, 0, 1,};
        vector<int> col {1, 0, -1, 0};
        int st = 0;
        while (fresh.size() > 0) {
            vector<string> infected;
            for (int r = 0 + st ;r<rotten.size();r++){
                int i = rotten[r][0] - '0';
                int j = rotten[r][1] - '0';
                for(int d=0;d<4;d++) {
                    string s = "" + to_string(i+row[d]) + to_string(j+col[d]);
                    vector<string>::iterator it;
                    it = std::find (fresh.begin(), fresh.end(), s); 
                    if (it !=fresh.end()) {
                        infected.push_back(s);
                        fresh.erase(it);
                    }
                }
                // rotten.erase(rotten.begin() + r);
                // rotten.pop_front();
            }
            if (infected.size() == 0 && fresh.size() != 0) {
                return -1;
            }
            minutes++;
            rotten.clear();
            rotten = infected;
            // st = rotten.size();
        }
        return minutes;
    }
};
