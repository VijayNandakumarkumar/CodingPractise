/*

LeetCode: 252

*/


#include<bits/stdc++.h>

using namespace std;


int main() {
    // vector<vector<int> > v {{0, 30}, {15, 20}, {5, 10} };
    vector<vector<int> > v {{7, 10}, {2, 4}};
    sort(v.begin(), v.end());
    for (int i = 0;i<v.size() - 1;i++) {
        if (v[i][1] > v[i + 1][0]) {
            cout<<"False";
            return 0;
        }
    }
        cout<<"true";
    return 0;
}
