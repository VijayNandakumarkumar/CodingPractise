/*

Strongly connected graph - Kosaraju's Algorithm.

Techdose.

time: O(|V| + |E|)
space: O(V+E)

for expl for Big O: https://www.interviewbit.com/tutorial/breadth-first-search/#:~:text=For%20a%20directed%20graph%2C%20the,graph%2C%20each%20edge%20appears%20twice.&text=The%20time%20complexity%20for%20this,O(V%20%2B%20E).

*/


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

#define V 8

unordered_map<int, vector<int>> adj, rev;
vector<bool> visited (V, false);
stack<int> st;
vector<set<int>> ans;

void dfs1(int v) {
    visited[v] = true;
    for(int j: adj[v]) {
        if (!visited[j]) {
            dfs1(j);
        }
    }
    st.push(v);
}

void dfs2(int v, set<int> &s) {
    visited[v] = true;
    s.insert({v});
    for (int j: rev[v]) {
        if (!visited[j]) {
            dfs2(j, s);
        }
    }
}

void reverse() {
    for(int i = 0;i<V;i++) {
        for(int j: adj[i]) {
            rev[j].push_back(i);
        }
    }
}

void findSccs() {
    
    for(int i = 0;i<V;i++) {
        if (!visited[i]){
            dfs1(i);
        }
    }
    for(int i=0;i<V;i++) {
        visited[i] = false;
    }
    reverse();
    
    while(!st.empty()) {
        set<int> s;
        int i = st.top();
        st.pop();
        if (visited[i]) {
            continue;
        }
        dfs2(i, s);
        ans.push_back(s);
    }
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[5].push_back(6);
	adj[6].push_back(4);
	adj[6].push_back(7);

	findSccs();
	cout<<"\n The number of SCCs are "<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++) {
	    set<int> s = ans[i];
	    for(auto j=s.begin();j!=s.end();j++) {
	        cout<<*j<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
