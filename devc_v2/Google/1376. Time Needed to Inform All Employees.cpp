/*

1376. Time Needed to Inform All Employees

A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

 

Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.

Example 2:

Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

*/

class Solution {
public:
    
    // From discussion.
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        int res = 0;
        for(int i =0;i<n;i++){
            res = max(res,dfs(i,manager,informTime));
        }
        return res;
    }
    
    int dfs(int idx, vector<int>& manager, vector<int>& informTime){
        if(manager[idx]!=-1){
            informTime[idx] += dfs(manager[idx],manager,informTime);
            manager[idx] = -1;
        }
        return informTime[idx];
    }

    /* From discussion and below our solution are similar.
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n]; 
        for(int i=0;i<n;++i)
        {     if(manager[i]!=-1)
            adj[manager[i]].push_back(i); // making an adjajency list so that employee is assigned to manager
        }
        queue<pair<int,int>>q;  //queue to store current node(during traversal) and time taken by this node+time of its previous manager to inform its subordinates
        int ans=INT_MIN;// to store final maximum time
        q.push({headID,informTime[headID]});
        while(!q.empty())
        {
            int node =q.front().first;
            int tt=q.front().second;
            ans=max(ans,tt); //updating ans if maximum value is encountered
            q.pop();
            for(auto x:adj[node])
            {
                q.push({x,informTime[x]+tt}); //traversing every suboordinates
            }
        }
        return ans;// return ans
    }*/
    
    /*
    #define iPair pair<int, int>
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n==1) {
            return informTime[0];
        }
        // unordered_map<int, vector<int>> m;
        vector<int>m[n]; 
        for(int i=0; i<n; i++) {
            if (manager[i] == -1)
                continue;
            m[manager[i]].push_back(i);
        }
        
        queue<iPair> q;
        q.push({headID, informTime[headID]});
        int time = 0, ans = 0;
        while(!q.empty()) {
            int id = q.front().first;
            int time = q.front().second;
            q.pop();
            cout<<id<<" ";
            ans = max(ans, time);
            for(auto x : m[id]) {
                q.push({x, time + informTime[x]});
            }
            // for (int i=0; i<m[id].size(); i++) {
            //     q.push({m[id][i], time + informTime[m[id][i]]});
            // }
        }
     return ans;   
    }*/
    
};