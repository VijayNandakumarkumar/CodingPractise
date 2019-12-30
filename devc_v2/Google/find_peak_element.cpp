#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    for(int i=0;i<(int)nums.size()-1;i++){
        if((nums[i]> nums[i+1])){
            return i;
        }
    }
	return (int)nums.size()-1;
}


int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(8);
	cout<<findPeakElement(v);
	return 0;
}
