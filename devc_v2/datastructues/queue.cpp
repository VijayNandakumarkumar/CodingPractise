#include<bits/stdc++.h>

using namespace std;


#define MAX  5

int que[MAX];

int top_counter = 0;

int rear = -1;
int front = 0;

bool isFull(){
	return top_counter == MAX;
}

bool isEmpty(){
	return top_counter == 0;
}

void insert(int data){
	if(!isFull()){
		que[++rear] = data;
		top_counter++;
	}
}

int remove(){
	if(!isEmpty()){
		top_counter--;
		return que[front++];
	}
	return NULL;
}

int main(){

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	cout<<top_counter;
	cout<<remove();
	cout<<top_counter;
	return 0;
}
