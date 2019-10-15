//expression parsing using shunting yard

#include<bits/stdc++.h>

using namespace std;

void convert(vector<string> &v, vector<string> &s){
	char symbol=' ';
}

int main(){
	string s="1*2+3";
	vector<string> infix, postfix;
	
	infix.push_back(s);
	vector<string>:: iterator it;
	
	convert(infix, postfix);
	
	return 0;
}
