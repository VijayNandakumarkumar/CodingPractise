#include <bits/stdc++.h>
using namespace std;

void flip(vector<int> &v, int index) {
    int i = 0;
    int j = index;
    int temp = 0;
    while (i<j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

vector<int> pancakeSort(vector<int> &v, int n) {
    while(n > 0) {
        int largeElement = *max_element(v.begin(), v.begin() + n);
        int index = distance(v.begin(), find(v.begin(), v.end(), largeElement));
        flip(v, index);
        flip(v, n-1);
        n--;
    }
    return v;
}


int main() {
    // Write C++ code here
    vector<int> v {2, 1, 5, 3, 4};
    v = pancakeSort(v, (int)v.size());
    for(auto it = v.begin();it!= v.end();it++) {
        cout<<*it;
    }
    return 0;
}
