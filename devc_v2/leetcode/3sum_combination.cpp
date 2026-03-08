#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	void combinationUtil(vector<int>& nums , int data[], int start, int end, int index, int r, vector<vector<int> >& result, int num){
		
		if(index==r){	
			if(accumulate(data, data+3, 0)==0)
				{
					cout<<"YEs";
					cout<<data[0];
					cout<<data[1];
					cout<<data[2];
					for(int j=0;j<3;j++){		
						cout<<"hello";
						result[num][j]=data[j];
					}
					cout<<"\n Came after";
					num++;
				}
			return;
			}
			for(int i=start;((i<=end)&&(end-i+1>=r-index));i++){
				data[index]=nums[i];
				combinationUtil(nums, data, start+1, end, index+1, r, result, num);
				while(nums[i]==nums[i+1])
					i++;
			}
		}

	vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int n=(int)nums.size();
        int data[3];
        combinationUtil(nums, data, 0, n-1, 0, 3, result, 0);
        for(int i=0;i<1;i++){
        	for(int j=0;j<3;j++)
        	{
        		cout<<result[i][j]<<"\t";
			}
			cout<<"\n";
		}
     return result;   
    }
};

int main(){
	Solution s;
	int arr[] = {-1, 0, 1, 2, -1, -4};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+n);
	vector<int> vect(arr, arr+n);
	s.threeSum(vect);
	return 0;
}

/*
15. 3Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

*/

// Best Solution O(log m + n)
// Neet code: https://www.youtube.com/watch?v=jzZsG8n2R9A

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()==0)
             return {};
        sort(nums.begin(), nums.end());
        if (nums[0]>0)
             return {};

        vector<vector<int>> result;
        set<vector<int>> sum_set;
        for (int s=0; s<nums.size(); s++) {
            if (s>0 && nums[s] == nums[s-1])
                continue;
            int a = nums[s];
            int i = s+1, j = nums.size()-1;
            while(i<j) {
                 int sum=a+nums[i] + nums[j];
                 if (sum>0) {
                    j--;
                 } else if (sum<0) {
                    i++;
                 } else {
                    vector<int> vs {a, nums[i], nums[j]};
                    result.push_back(vs);
                    i++;
                    j--;
                    while(i<j && nums[i] == nums[i-1])
                        i++;
                 }
            }
            
        }
        return result;
    }
};
