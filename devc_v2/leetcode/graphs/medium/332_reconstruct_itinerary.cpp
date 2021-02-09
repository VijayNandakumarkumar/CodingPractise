/*

332. Reconstruct Itinerary

(tech dose)

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

*/

//Solution: 1 (O(E)) because we visit each edge only once.

class Solution {
public:
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> m;
        for (int i = 0;i< tickets.size();i++)  {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> s;
        vector<string> v;
        s.push("JFK");
        while(!s.empty()) {
            string source = s.top();
            if (m[source].size() == 0) {
                v.push_back(source);
                s.pop();
            }
             else {
                auto it = m[source].begin();
                 s.push(*it);
                 cout<<*it;
                m[source].erase(it);
                
             }
        }
        
        reverse(v.begin(), v.end());
        return  v;
    }
    
    
};

//Solution-2: Instead of multiset priority queue can be used.


//Solution-3: DFS

void dfs(string src, vector<string> &v, map<string, multiset<string>> &m) {
        while(!m[src].empty()) {
            string dest = *(m[src].begin());
            m[src].erase(m[src].begin()); //not using string value to delet4e because it's multiset and there may be multiple values of same dest. so use it.
            dfs(dest, v, m);
        }
        v.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> m;
        for (int i = 0;i< tickets.size();i++)  {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> v;

        dfs("JFK", v, m);
        reverse(v.begin(), v.end());
        return  v;
    }
