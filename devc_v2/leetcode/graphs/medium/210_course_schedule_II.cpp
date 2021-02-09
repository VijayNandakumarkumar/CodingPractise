/*

210. Course Schedule II

There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

*/

//Solution: O(V+E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if (prerequisites.size() == 0)  {
            for (int i = numCourses - 1;i>=0;i--) {
                ans.push_back(i);
            }
            return ans;
        }
        map<int, vector<int>> v;
        for(int i = 0;i<prerequisites.size();i++) {
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        if (detectCycle(v, numCourses)) {
            return {};
        }
        vector<bool> visited(numCourses, false);
        for(auto it = v.begin();it!=v.end();it++) {
            if (!visited[it->first]) 
                topSort(it->first, visited, v, ans);
        }
        vector<int> n_ans;
        for(int i = 0;i<numCourses;i++){
            if (!visited[i]) {
                n_ans.push_back(i);
            }
        }
        n_ans.insert(n_ans.begin(), ans.begin(), ans.end());
        return n_ans;
    }
    void topSort(int i, vector<bool> &visited, map<int, vector<int>> &v, vector<int> &s) {
        visited[i] = true;
        for(int j = 0;j<(int)v[i].size();j++) {
            if (visited[v[i][j]]) {
                continue;
            }
            topSort(v[i][j], visited, v, s);
        }
        s.push_back(i);
        
    }
    bool detectCycle(map<int, vector<int>> &v, int n) {
        vector<bool> visited(n, false);
        vector<int> t;
        
        for(auto it = v.begin();it!=v.end();it++) {
            if (!visited[it->first]) {
                if(cycle(it->first, t, visited, v)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycle(int i, vector<int> &track, vector<bool> &visited, map<int, vector<int>> &v) {
    track.push_back(i);
    visited[i] = true;
    for(int j = 0;j<(int)v[i].size();j++) {
        if (visited[v[i][j]]) {
            if (find(track.begin(), track.end(), v[i][j]) != track.end()) {
                return true;
            }
            continue;
        }
        if (cycle(v[i][j], track, visited, v))
            return true;
    }
    track.pop_back();
    return false;
}
    
};
