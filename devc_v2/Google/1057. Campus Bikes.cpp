/*

1057. Campus Bikes

On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. All the given positions are unique.

Assign a bike to each worker. Among the available bikes and workers, we choose the (workeri, bikej) pair with the shortest Manhattan distance between each other and assign the bike to that worker.

If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index. If there are multiple ways to do that, we choose the pair with the smallest bike index. Repeat this process until there are no available workers.

Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith worker is assigned to.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

 

Example 1:

Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
Explanation: Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].

Example 2:

Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
Explanation: Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].

*/

// 1. We though of all 3 approaches greedy (slightly), bucket (yes) and priority queue (yes).
// 2. All the sol below are from leetcode sol.

class Solution {
public:
    int dist(vector<int> &worker, vector<int> &bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    /* TLE -> Greedy
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wlen = workers.size(), blen = bikes.size();
        vector<vector<int>> tuples;
        for (int i=0; i<wlen; i++) {
            for (int j=0; j<blen; j++) {
                tuples.push_back({dist(workers[i], bikes[j]), i, j});
            }
        }
        vector<int> bikeSt (blen, -1);
        vector<int> workerSt (wlen, -1);
        int count=0;
        sort(tuples.begin(), tuples.end());
        
        for(int i=0; i<tuples.size(); i++) {
            vector<int> combo = tuples[i];
            if(workerSt[combo[1]] == -1 && bikeSt[combo[2]] == -1) {
                workerSt[combo[1]] = combo[2];
                bikeSt[combo[2]] = combo[0];
                count++;
            }
            if (count == wlen) {
                return workerSt;
            }
        }
        return workerSt;
    }
    */
    #define iPair pair<int, int>
    
    /* Working bucket sort
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wlen = workers.size(), blen = bikes.size();
        map<int, vector<iPair>> m;
        for (int i=0; i<wlen; i++) {
            for (int j=0; j<blen; j++) {
                int distance = dist(workers[i], bikes[j]);
                m[distance].push_back({i, j});
            }
        }
        vector<int> bikeSt (blen, -1);
        vector<int> workerSt (wlen, -1);
        int count=0;
        // sort(tuples.begin(), tuples.end());
        
        for (auto it = m.begin(); it!=m.end(); it++) {
            vector<iPair> disPairs = it->second;
            // sort(disPairs.begin(), disPairs.end());
            for (int i=0; i<disPairs.size(); i++) {
                iPair wb = disPairs[i];
                if(workerSt[wb.first] == -1 && bikeSt[wb.second] == -1) {
                    workerSt[wb.first] = wb.second;
                    bikeSt[wb.second] = 0;
                    count++;
                }
                if (count == wlen) {
                    return workerSt;
                }
            }
        }
        
        return workerSt;
    }
    */
    
    // Priority queue approach.
     vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wlen = workers.size(), blen = bikes.size();
        vector<iPair> v [wlen];
         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
         
        for (int i=0; i<wlen; i++) {
            for (int j=0; j<blen; j++) {
                int distance = dist(workers[i], bikes[j]);
                v[i].push_back({distance, j});
            }
            sort(v[i].begin(), v[i].end());
            pq.push({v[i][0].first, i, v[i][0].second});
            v[i].erase(v[i].begin());
        }
        vector<int> bikeSt (blen, -1);
        vector<int> workerSt (wlen, -1);
        int count=0;
         
        while(!pq.empty()) {
            vector<int> ele = pq.top();
            pq.pop();
            if(workerSt[ele[1]] == -1 && bikeSt[ele[2]] == -1) {
                workerSt[ele[1]] = ele[2];
                bikeSt[ele[2]] = 0;
                count++;
            } else {
                pq.push({v[ele[1]][0].first, ele[1], v[ele[1]][0].second});
                v[ele[1]].erase(v[ele[1]].begin());
            }
            if (count == wlen) {
                return workerSt;
            }
        }
        
        return workerSt;
    }
};