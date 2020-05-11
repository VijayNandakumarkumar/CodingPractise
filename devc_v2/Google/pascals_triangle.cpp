#include<bits/stdc++.h>
using namespace std;

int main(){
	int coef = 0;
	int row=5;
	for(int i=0;i<row;i++){
		for(int space=1;space<=row-i;space++){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			if((i==0)||(j==0)){
				coef = 1;
			}
			else{
				coef = coef*(i-j+1)/j;
			}
			cout<<coef<<" ";
		}
		cout<<endl;
	}
	return 0;
}
