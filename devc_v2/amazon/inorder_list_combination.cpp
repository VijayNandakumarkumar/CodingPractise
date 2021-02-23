//Current solution below is with string, so convert vector to string and use.

//My Solution

#include <bits/stdc++.h>
using namespace std;


void printInterleaved(string s1, string s2, int im, int m, int in, int n, string current) {
    
    if (current.length() == m + n) {
        cout<<current<<"\n";
        return;
    }
    
    for (int i=im; i<m; i++) {
        current.push_back(s1[i]);
        printInterleaved(s1, s2, i + 1, m, in, n, current);
        current.pop_back();
    }
    
    for (int i=in; i<n; i++) {
        current.push_back(s2[i]);
        printInterleaved(s1, s2, im, m, i + 1, n, current);
        current.pop_back();
    }
}

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
	char *str1 = "98";
	char *str2 = "21";
	printInterleaved(str1, str2, 2, 2);
	}
