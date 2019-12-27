#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node *head = NULL;
typedef struct node* Node;

void printlist(){
	struct node* current = head;
	cout<<"\n";
	for(;current!=NULL;current=current->next){
		cout<<current->data<<"\t";
	}
}

int lengthOfList(){
	Node current = head;
	int length = 0;
	for(;current!=NULL;current = current->next){
		length++;
	}
	return length;
}

bool isEmpty(){
	return head == NULL;
}

void insertfirst(int data){
	Node new_node = (Node)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	
	if(head == NULL){
		head = new_node;
		return;
	}
	
	new_node->next = head;
	head = new_node;

}

Node deletefirst(){
	Node tempnode = NULL;
	
	if(head == NULL){
		return NULL;
	}
	else{
		tempnode = head;
		head = head->next;
	}
	return tempnode;
}

Node find(int data){
	Node current = head;
	if(head == NULL){
		return NULL;
	}
	else{
		while(current->data != data){
			if(current == NULL){
				return NULL;
			}
			else{
				current = current->next;
			}
		}
	}
	return current;
}

void sort(){
	Node current = head;
	int i=0, j=0;
	int temp = 0;
	int n=lengthOfList();
	
	for(i=0;i<n;i++){
		current = head;
		for(j=0;j<n-1;j++){
			if(current->data > current->next->data){
				temp = current->data;
				current->data =current->next->data;
				current->next->data =temp;
			}
			current = current->next;
		}
	}
}
void reverse(){
	Node current = head;
	Node prev= NULL;
	Node next = NULL;
	
	while(current != NULL){
		next= current->next;
		current->next = prev;
		prev= current;
		current = next;
	}
	head = prev;
}
int main(){
	
	insertfirst(1);
	insertfirst(2);
	insertfirst(3);
	insertfirst(4);
	
	insertfirst(7);
	insertfirst(5);
	insertfirst(8);
	insertfirst(0);
	
	printlist();
	
	deletefirst();
	
	printlist();
	
	sort();
	printlist();
	
	return 0;
}
