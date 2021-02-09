/*

207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> v;
        for(int i = 0;i<prerequisites.size();i++) {
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        if (detectCycle(v, numCourses)) {
            return false;
        }
        return true;
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



