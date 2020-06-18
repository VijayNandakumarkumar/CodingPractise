/**
1470. Shuffle the Array
Easy

180

21

Add to List

Share
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
*/


#include<bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int i = 0, j = nums.size()/2;
        for(int k = 0; k<nums.size()/2;k++){
            v.push_back(nums[i]);
            v.push_back(nums[j]);
            i++;
            j++;
        }
        return v;
    }
    
void display(vector<int> &v) {
	
		for(int j=0;j<v.size();j++) {
			cout<<v[j]<<"\t";
		}
		
	cout<<"\n";
}

int main() {
	
	vector<int> v {2,5,1,3,4,7};
	display(v);
	v = shuffle(v, 3);
	display(v);
	return 0;
}
