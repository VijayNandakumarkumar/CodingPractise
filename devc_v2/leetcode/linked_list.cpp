#include<bits/stdc++.h>\

using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

void printList(){
	struct node* current = head;
	printf("\n\n");
	for(;current!=NULL;current=current->next){
		printf("\t%d", current->data);
	}
}

void insertFirst(int data){
	struct node* new_node =  (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	
	if(head == NULL){
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
	return;
}

struct node* deleteFirst(){
	struct node* temp = NULL;
	
	temp = head;
	head = head->next;
	
	return temp;	
}

int length(){
	int length=0;
	struct node* current;
	for(current = head; current != NULL; current = current->next){
		length++;
	}
	return length;
}

struct node* find(int key){
	
	if(head == NULL){
		return NULL;
	}
	
	struct node* current = head;
	
	while(current->data != key){
		if(current->next == NULL){
			return NULL;
		}
		else{
			current=current->next;
		}
	}
	return current;
}

int main(){
	insertFirst(1);
	insertFirst(2);
	insertFirst(3);
	insertFirst(4);
	insertFirst(5);
	insertFirst(6);
	insertFirst(7);
	
	printList();
	
	deleteFirst();
	
	printList();
	
	printf("\ndata found %d", find(4)->data);
	
	return 0;
}
