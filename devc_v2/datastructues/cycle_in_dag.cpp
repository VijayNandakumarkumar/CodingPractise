// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(4);
vector<bool> visited(4, false);

bool cycle(int i, vector<int> &track, vector<bool> &visited) {
    cout<<"Incomung vertex "<<i<<"\n";
    track.push_back(i);
    visited[i] = true;
    for(int j = 0;j<(int)v[i].size();j++) {
        cout<<"\n item "<<v[i][j]<<" is ";
        if (visited[v[i][j]]) {
            if (find(track.begin(), track.end(), v[i][j]) != track.end()) {
                cout<<" visited and is parent \n";
                return true;
            }
            cout<<" just visited not parent track size "<<track.size()<<"\n";
            continue;
        }
        cout<<" not visited yet \n";
        if (cycle(v[i][j], track, visited))
            return true;
    }
    cout<<" i = "<<i<<" track size "<<track.size()<<"\n";
    track.pop_back();
    cout<<" i = "<<i<<" track size "<<track.size()<<"\n";
    return false;
}
int main() {
    for(int i = 0;i<4;i++) {
        for (int j = 0;j<v[i].size();j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    v[0].push_back(1);
    v[1].push_back(2);
    v[2].push_back(3);
    v[3].push_back(2);
    // Write C++ code here
    vector<int> t;
    for (int i = 0;i<4;i++) {
        cout<<"Sending vertex "<<i<<"\n";
        if (!visited[i]) {
            if(cycle(i, t, visited)) {
                cout<<"false";
                return 0;
            }
        }
    }
    cout<<"True";
    return 0;
}
