#include<bits/stdc++.h>;

using namespace std;
void printing(char *str1, char *str2, char *new_string, int m, int n, int i){
	if((m==0)&&(n==0)){
		cout<<new_string<<"\n";
	}
	if(m!=0){
		new_string[i] = str1[0];
		printing(str1 + 1, str2, new_string, m - 1, n, i+1);
	}
	if(n!=0){
		new_string[i] = str2[0];
		printing(str1, str2 + 1, new_string, m, n - 1, i+1);
	}
}

void printInterleaved(char *str1, char *str2, int m, int n){
	char *new_string = (char*)malloc((m + n) * sizeof(char));
	printing(str1, str2, new_string, m, n, 0);
}
int main(){
	char *str1 = "abc";
	char *str2 = "ABC";
	printInterleaved(str1, str2, 3, 3);
	}
