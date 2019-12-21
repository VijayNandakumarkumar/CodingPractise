#include<bits/stdc++.h>

using namespace std;
int main(){
	int a[3][2]={{0, 30}, {5, 10}, {15, 20}};
	int num_of_rooms=0;
	for(int i=0;i<3;i++){
		if(a[i][1]>a[i+1][0]){
			num_of_rooms++;
		}
	}

	cout<<num_of_rooms;
	return 0;
}
