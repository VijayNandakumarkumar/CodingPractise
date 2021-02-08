/*

997. Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3

*/

//Solution 1: Optimal Space (O(N)) Time is same as next solution (O(E))

int findJudge(int N, vector<vector<int>>& trust) {
        map<int, bool> adj;
        vector<int> deg (N + 1, 0);
        for(int i = 0;i<trust.size();i++) {
            // cout<<trust[i][0]<<" "<<trust[i][1]<<"\n";
            deg[trust[i][1]]++;
            deg[trust[i][0]]--;
        }
        int judge = -1;
        for (int i = 1;i<=N;i++) {
            if (deg[i] == N-1) {
                    return i;
            }
        }
        return -1;
    }

// Solution: 2 (O(N) - but one array is less)

int findJudge(int N, vector<vector<int>>& trust) {
        map<int, bool> adj;
        vector<int> inDeg (N + 1, 0);
        vector<int> outDeg (N + 1, 0);
        for(int i = 0;i<trust.size();i++) {
            // cout<<trust[i][0]<<" "<<trust[i][1]<<"\n";
            inDeg[trust[i][1]]++;
            outDeg[trust[i][0]]++;
        }
        int judge = -1;
        for (int i = 1;i<=N;i++) {
            if (outDeg[i] == 0) {
                if (inDeg[i] == N-1) {
                    return i;
                }
                return -1;
            }
        }
        return -1;
    }

