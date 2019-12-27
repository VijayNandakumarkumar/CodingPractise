#include<bits/stdc++.h>

using namespace std;

#define MAX 5

int top = -1;


int stk[MAX];

bool isFull(){
	return top==MAX;
}

bool isEmpty(){
	return top==-1;
}

void push(int data){
	if(!isFull()){
		stk[++top] = data;
	}
}

int pop(){
	if(!isEmpty()){
		return stk[top--];
	}
	return NULL;
}

int peek(){
	if(!isEmpty()){
		return stk[top];
	}
	return NULL;
}

int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	
	cout<<peek();
	cout<<pop();
	cout<<isFull();
	cout<<isEmpty();
	cout<<peek();
	cout<<pop();
	return 0;
}
