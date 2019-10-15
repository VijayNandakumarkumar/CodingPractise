#include<bits/stdc++.h>

using namespace std;

#define MAX 10

int queue_q[MAX];

int itemCount = 0;

int front = 0;
int rear = -1;

void print(){
	printf("\n");
	for(int i = 0;i<itemCount;i++){
		printf("\t%d", queue_q[i]);
	}
}

int isFull(){
	return itemCount == MAX;
}

void insert(int data){
	if(!isFull()){
		if(rear == MAX){
			rear = -1;
		}
		
		queue_q[++rear] = data;
		itemCount++;
	}
}

int isEmpty(){
	return itemCount == 0;
}
int remove(){
	
	int data;
	if(!isEmpty()){
		data = queue_q[front++];
		if(front==MAX){
			front = 0;
		}
		
		itemCount--;
		
		
	}
	return data;
}

int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	
	print();
	
	printf("\ndataa removed %d\n", remove());
	
	
	
}
