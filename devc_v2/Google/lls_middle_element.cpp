/*

876. Middle of the Linked List

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

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
