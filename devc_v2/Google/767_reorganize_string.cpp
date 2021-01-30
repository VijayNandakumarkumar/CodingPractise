/*

767. Reorganize String

HINT: Since frequency of chars involved think of map/pair and max heap.

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""

*/


class Solution {
public:
    string reorganizeString(string str) {
        auto comp = [](pair<char, int> &a, pair<char, int> &b) {
            return a.second < b.second;
        };
        map<char, int> m;
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> q(comp);
        for(int i = 0;i<str.length();i++) {
            m[str[i]]++;
        }
        for(auto it = m.begin();it != m.end(); it++) {
            // cout<<it->first<<" "<<it->second<<endl;
            q.push({it->first, it->second});
        }
        string new_str;
        while (q.size() > 1) {
            
            pair<char, int> cur = q.top();
            q.pop();
            pair<char, int> nextCur = q.top();
            q.pop();
            new_str += cur.first;
            new_str += nextCur.first;
            cur.second -= 1;
            nextCur.second -= 1;
            if (cur.second > 0) {
                q.push(cur);
            }
            if (nextCur.second > 0) {
                q.push(nextCur);
            }
        }
        if (!q.empty()) {
            pair<char, int> last = q.top();
            q.pop();
            if (last.second > 1) {
                return "";
            }
            new_str += last.first;
        }
        
        return new_str;
        }
};
