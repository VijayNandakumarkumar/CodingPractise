//expression parsing using shunting yard

#include<bits/stdc++.h>

using namespace std;

bool isOperator(char symbol){
	switch(symbol){
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}
int precedence(char symbol){
	switch(symbol){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
			
		case '/':
			return 2;
		default:
			return 0;
}
}
void convert(string &v, vector<string> &s)
{
	char symbol=' ';
	int i=0;
	vector<char> operand;
	stack<char> stk;
	stk.push('#');
	while(i<v.length()){
		symbol = v[i++];
		if(!isOperator(symbol)){
			operand.push_back(symbol);
		}
		else{
			if(symbol == '('){
				stk.push(symbol);
			}
			else if(symbol == ')'){
				while(stk.top() == '('){
					operand.push_back(stk.top());
					stk.pop();
				}
				stk.pop();
			}
			else{
				if(precedence(symbol) > precedence(stk.top())){
					stk.push(symbol);
				}
				else{
					while(precedence(symbol) < precedence(stk.top())){
						operand.push_back(stk.top());
						stk.pop();
					}
					stk.push(symbol);
				}
			}
		}
	}
	while(stk.size()!=1){
		operand.push_back(stk.top());
		stk.pop();
	}
	
	for(int i=0;i<operand.size();i++){
		cout<<operand[i];
	}
	
}

int main(){
	string s="1*2+3";
	vector<string> infix, postfix;
	
	infix.push_back(s);
	vector<string>:: iterator it;
	
	convert(s, postfix);
	
	return 0;
}
