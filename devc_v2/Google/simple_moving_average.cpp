#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[5] = { 1, 3, 5, 6, 8 };
	int todel = 0;
	int i=0, depth = 0;
	double sum = 0.0;
	for(i=0;i<5;i++) {
		if(depth == 3){
			sum -= arr[todel];
			todel++;
			sum += arr[i];
			cout<<"the simple moving average is "<<(sum / 3)<<"\n";
		}
		else{
			sum +=arr[i];
			depth++;
			cout<<"the simple moving average is "<<(sum / 3)<<"\n";
		}
	}
	return 0;
}
