#include<bits/stdc++.h>

using namespace std;

bool hasPairWithSum(vector<int> &data, int sum){
	int low = 0;
	int high = (int)(data.size() - 1);
	int s = 0;
	while(low<high){
		s = data[low]+data[high];
		if(s==sum){
			return true;
		}
		else if(s>sum){
			high--;
		}
		else{
			low++;
		}
	}
	return false;
}


int main(){
	vector<int> v{1, 2, 4, 4};
	cout<<hasPairWithSum(v, 8);
	
	return 0;
}

