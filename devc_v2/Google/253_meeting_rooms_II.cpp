/*

253. Meeting Rooms II
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1


*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        auto comp = [] (pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        q.push({intervals[0][0], intervals[0][1]});
        
        for (int i = 1; i<intervals.size(); i++) {
            pair<int, int> p = q.top();
            q.pop();
            // cout<<"i "<<i<<" "<<p.first<<" "<<p.second<<"\n";
            if (intervals[i][0] >= p.second) {
                p.second = intervals[i][1];
            } else {
                q.push({intervals[i][0], intervals[i][1]});
            }
            q.push(p);
        }
        return q.size();
    }
};

 
