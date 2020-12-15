/*
Coded by following algo of abul dahir.
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

int knap_sack_wpr(vector<pair<double, ipair> > &wp, int W) {
    int max_profit = INT_MIN;
    do {
        int w = 0, i = 0, p=0;
        for(int i=0;i<(int)wp.size() && w<=W;i++){
            if ((w + wp[i].second.first) <= W) {
                cout<<"weight = "<<w<<" profit = "<<p<<"\n";
                w += wp[i].second.first;
                p += wp[i].second.second;
            }
        }
        max_profit = max(max_profit, p);
        cout<<"profit = "<<p<<"max_profit = "<<max_profit<<"\n";
    }while(next_permutation(wp.begin(), wp.end()));
    return max_profit;
}

int main(){
	vector<int> vt{60, 100, 120};
	vector<int> wt{10, 20, 30};
	vector<pair<double, ipair> > wp;

	for (int i = 0;i<(int)wt.size();i++) {
	    double wpr = vt[i]/wt[i];
	    wp.push_back({wpr, {wt[i], vt[i]}});
	}
	int W = 50;
        sort(wp.begin(), wp.end());
        cout<<knap_sack_wpr(wp, W);

	return 0;
}
