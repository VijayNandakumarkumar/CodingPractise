#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node* Nde;

Nde head = NULL;
Nde last = NULL;



Nde newNode(int data){
	Nde new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
}


void insertIntoDll(Nde node){
	if(head == NULL){
		head = node;
		last = node;
		return;
	}
	last->right = node;
	node->left = last;
	last = node;
	return;
}
void printInorder(Nde root){
	if(root == NULL)
		{
			return;
		}
	printInorder(root->left);
	insertIntoDll(root);
	printInorder(root->right);
	return;
	
}

void printDll(Nde head){
	
	if(head == NULL){
		cout<<"Empty Dll";
		return;
	}
	Nde current = head;
	while(current != NULL){
		cout<<current->data<<" ";
		current = current->right;
	}
}

int main(){
	
	Nde n1 = newNode(10);
	Nde n2 = newNode(12);
	Nde n3 = newNode(15);
	n1->left = n2;
	n1->right = n3;
	
	n2->left = newNode(25);
	n2->right = newNode(30);
	n3->left = newNode(36);
	
	printInorder(n1);
	printDll(head);
	return 0;
}
