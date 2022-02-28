/*

1101. The Earliest Moment When Everyone Become Friends

here are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

 

Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301

Example 2:

Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3


*/

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<set<int>> res;
        int curT = 0, left = 0, right = 0;
        bool found = false;
        sort(logs.begin(), logs.end());
        for (int i=0; i<logs.size(); i++) {
            found = false;
            curT = logs[i][0];
            left = logs[i][1];
            right = logs[i][2];
            int leftInd = -1, rightInd = -1;
            for (int j=0; j<res.size();j++) {
                if (res[j].find(left) != res[j].end()) {
                    leftInd = j;
                }
                if (res[j].find(right) != res[j].end()) {
                    rightInd = j;
                }
                if ((leftInd != -1) && (rightInd != -1)) {
                    break;
                }
            }
            if ((leftInd != -1) && (rightInd != -1)) {
                if (leftInd == rightInd) {
                    found = true;
                } else {
                    res[leftInd].insert(res[rightInd].begin(), res[rightInd].end());
                    res.erase(res.begin() + rightInd);
                    found = true;
                }
            } else if (leftInd != -1) {
                res[leftInd].insert(right);
                found = true;
            } else if (rightInd != -1) {
                res[rightInd].insert(left);
                found = true;
            }
            if(!found) {
                set<int> v {left, right};
                res.push_back(v);
            }
            if (res.size() == 1 && res[0].size() == n) {
                return curT;
            }
        }
        return -1;
    }
};