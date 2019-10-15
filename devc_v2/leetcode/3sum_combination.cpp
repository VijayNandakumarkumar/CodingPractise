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
