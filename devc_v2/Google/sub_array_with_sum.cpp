#include<bits/stdc++.h>

using namespace std;

//Sliding window

bool hasPairWithSum(vector<int> &data, int sum){
	int wsum = 0;
	queue<int> q;
	int i=0;
	for(i=0;i<(int)data.size();i++){
		wsum+=data[i];
		q.push(data[i]);
		while(wsum>sum){
			wsum -= q.front();
			q.pop();
		}
		if(wsum==sum){
			cout<<q.front();
			cout<<q.back();
			return true;
		}
}
	return false;
}

//bool hasPairWithSum(vector<int> &data, int sum){
//	vector<int> comp;
//	vector<int>::iterator it;
//	int remaining_sum = sum;
//	int i=0, j=0;
//	for(i=0;i<(int)data.size();i++){
//		comp.clear();
//		remaining_sum = sum;
//		for(j=i;j<(int)data.size(); j++){
//			if(remaining_sum>0){
//				it = find(comp.begin(), comp.end(), data[j]);
//				if(it!=comp.end()){
//					cout<<"start = "<<i+1<<"end = "<<j+1;
//					return true;
//				}
//				comp.push_back(remaining_sum-data[j]);
//				remaining_sum -= data[j];
//			}
//			else{
//				break;
//			}
//		}
//	}
//	return false;
//}


int main(){
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<hasPairWithSum(v, 14);
	
	return 0;
}

