#include<bits/stdc++.h>

using namespace std;

#define MAX 10
int stack_s[10];

int top = -1;

void printStack(){
	printf("\n");
	for(int i=0;i<=top;i++){
		printf("\t%d", stack_s[i]);
	}
}

int isFull()
{
	if(top == MAX){
		return 1;
	}
	return 0;
}

int isEmpty(){
	return top == -1;
}

void push(int data){
	stack_s[++top] = data;
}

int peek(){
	return stack_s[top];
}

int pop(){
	return stack_s[top--];
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	
	pop();
	printf("\npeeked %d\n", peek());
	printStack();
	
	return 0;
}
