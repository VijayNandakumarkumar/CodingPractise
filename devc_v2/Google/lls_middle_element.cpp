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


void print_middle_element(Node head){
	
	
	if(head!=NULL){
		Node slow_ptr = head;
		Node fast_ptr = head;
		while((fast_ptr!=NULL)&&(fast_ptr->next!=NULL)){
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		cout<<"The middle element is "<<slow_ptr->key;
	}
}

int main(){
	Node root = new_node(1);
	root->next = new_node(2);
	root->next->next = new_node(3);
	root->next->next->next = new_node(4);
	root->next->next->next->next = new_node(5);
	root->next->next->next->next->next = new_node(6);
	root->next->next->next->next->next->next = new_node(7);
	
	print_middle_element(root);
	return 0;
}
