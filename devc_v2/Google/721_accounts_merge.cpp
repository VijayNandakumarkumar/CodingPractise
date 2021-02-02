/*

721. Accounts Merge

Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

*/


Solution: 1 (Good runtime)

class Solution {
public:
    map<string, vector<string>> g;
    set<string> seen;
    vector<vector<string>> ans;
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> en;
        for(int i = 0; i < accounts.size();i++) {
            string name = accounts[i][0];
            for(int j = 1;j<accounts[i].size();j++) {
                string email = accounts[i][j];
                g[email].push_back(accounts[i][1]);
                g[accounts[i][1]].push_back(email);
                en[email] = name;
            }
        }

        for (int i = 0;i<accounts.size();i++) {
            for (int j = 1;j<accounts[i].size();j++) {
                if (seen.find(accounts[i][j]) == seen.end()) {
                    vector<string> sub_ans;
                    dfs(sub_ans, accounts[i][j]);
                    sort(sub_ans.begin(), sub_ans.end());
                    sub_ans.insert(sub_ans.begin(), en[accounts[i][j]]);
                    ans.push_back(sub_ans);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<string> &sub_ans, string s) {
        if (seen.find(s) != seen.end()) {
            return;
        }
        seen.insert(s);
        sub_ans.push_back(s);
        for(int i = 0;i<g[s].size();i++) {
            dfs(sub_ans, g[s][i]);
        }
    }
};

Solution: 2 (Sub optimal runtime)

class Solution {
public:
    map<string, vector<string>> g;
    set<string> seen;
    vector<vector<string>> ans;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> en;
        for(int i = 0; i < accounts.size();i++) {
            string name = accounts[i][0];
            for(int j = 1;j<accounts[i].size();j++) {
                string email = accounts[i][j];
                g[email].push_back(accounts[i][1]);
                g[accounts[i][1]].push_back(email);
                en[email] = name;
            }
        }

        for (auto it = g.begin();it!=g.end();it++) {
            if (seen.find(it->first) == seen.end()) {
                // cout<<"\n First "<<it->first<<"\n";
                stack<string> s;
                s.push(it->first);
                vector<string> comp;
                while(!s.empty()) {
                    string t = s.top();
                    seen.insert(t);
                    string u = getAdjUnvEmail(t);
                    if (u.length() == 0) {
                        if (find(comp.begin(), comp.end(), t) == comp.end()) {
                            comp.push_back(t);
                        }
                        s.pop();
                    } else {
                        // cout<<u<<" ";
                        s.push(u);
                        comp.push_back(u);
                    }
                }
                sort(comp.begin(), comp.end());
                string name = en[it->first];
                // cout<<"name "<<name<<"\n";
                // for (int k = 0;k<comp.size();k++) {
                //     cout<<comp[k]<<" ";
                // }
                // cout<<"\n";
                comp.insert(comp.begin(), en[it->first]);
                ans.push_back(comp);
            }   
        }
        return ans;
    }
    
    string getAdjUnvEmail(string s) {
        vector<string> emails = g[s];
        for (int i = 0; i<emails.size();i++) {
            string email = emails[i];
            if (seen.find(email) == seen.end()) {
                seen.insert(email);
                return email;
            }
        }
        return "";
    }
};
