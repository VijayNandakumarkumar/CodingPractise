/*

24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

Input: head = [1,2,3,4]
Output: [2,1,4,3]

*/

#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node* next;
};

typedef struct node* Node;

Node new_node(int key){
	Node n = (Node)malloc(sizeof(struct node));
	n->key = key;
	n->next = NULL;
	return n;
}

void swap(Node head, Node next){
	int temp = head->key;
	head->key = next->key;
	next->key =  temp;
}

void pairwiseswap(Node head){
	if((head!=NULL)&&(head->next!=NULL)){
		swap(head, head->next);
		pairwiseswap(head->next->next);
	}
}

void display(Node head){
	if(head!=NULL){
		cout<<"->"<<head->key;
		display(head->next);
	}
}
int main(){
	Node root = new_node(1);
	root->next = new_node(2);
	root->next->next = new_node(3);
	root->next->next->next = new_node(4);
	root->next->next->next->next = new_node(5);
	root->next->next->next->next->next = new_node(6);
	display(root);
	pairwiseswap(root);
	cout<<"\n";
	display(root);
	
	return 0;
}
