/*

1007. Minimum Domino Rotations For Equal Row.

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.

*/

//Solution-1: Optimal(O(N)) less number of comparisons and space optimal, check kevin's.

int minDominoRotations(vector<int>& A, vector<int>& B) {
        int minRot = min(
            numRotations(A[0], A, B),
            numRotations(B[0], A, B)
        );
        minRot = min(minRot, numRotations(A[0], B, A));
        minRot = min(minRot, numRotations(B[0], B, A));
        return (minRot == INT_MAX) ? -1: minRot;
    }
    
    int numRotations(int target, vector<int>& A, vector<int>& B) {
        int minRot = 0;
        for (int i = 0;i<A.size();i++) {
            if (A[i] != target) {
                if (B[i] == target) {
                    minRot++;
                    continue;
                }
                return INT_MAX;
            }
        }
        return minRot;
    }

//Solution-2: (O(n)) Sub space optimal.

int minDominoRotations(vector<int>& A, vector<int>& B) {
        auto comp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        };
        map<int, int> afreq;
        map<int, int> bfreq;
        for (int i =0;i<A.size();i++) {
            afreq[A[i]]++;
        }
        for (int i =0;i<B.size();i++) {
            bfreq[B[i]]++;
        }
        pair<int, int> aTop = {-1, -1};
        pair<int, int> bTop = {-1, -1};
        for(auto it = afreq.begin(); it!=afreq.end();it++) {
            if (it->second > aTop.second) {
                aTop.first = it->first;
                aTop.second = it->second;
            }
        }
        for(auto it = bfreq.begin(); it!=bfreq.end();it++) {
            if (it->second > bTop.second) {
                bTop.first = it->first;
                bTop.second = it->second;
            }
        }
        int aTopFreq = aTop.first;
        int bTopFreq = bTop.first;
        if (aTop.second == A.size() || bTop.second == B.size()) {
            return 0;
        }
        cout<<aTopFreq;
        cout<<bTopFreq;
        int rotationsA = 0;
        for (int i=0;i<A.size();i++) {
            if (A[i] != aTopFreq) {
                if (B[i] == aTopFreq) {
                    rotationsA++;
                    continue;
                }
                rotationsA = -1;
                break;
            }
        }
        int rotationsB = 0;
        for (int i=0;i<B.size();i++) {
            if (B[i] != bTopFreq) {
                if (A[i] == bTopFreq) {
                    rotationsB++;
                    continue;
                }
                rotationsB = -1;
                break;
            }
        }
        if ((rotationsA == -1) || (rotationsB == -1)) {
            return (rotationsA == -1) ? rotationsB : rotationsA;
        }
        return (rotationsA < rotationsB) ? rotationsA: rotationsB;
    }
