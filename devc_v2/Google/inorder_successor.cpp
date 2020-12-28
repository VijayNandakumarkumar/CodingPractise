/*
Leetcode: 285.
*/


#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

typedef struct node* Node;

Node new_node(int data){
	Node n = (Node)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	return n;
}
Node insert(Node root, int data){
	if(root == NULL){
		return new_node(data);
	}
	else{
		Node temp;
		if(data<root->data){
			temp = insert(root->left, data);
			root->left = temp;
			temp->parent=root;
		}
		else{
			if(data>root->data){
				temp = insert(root->right, data);
				root->right = temp;
				temp->parent=root;
			}
		}
	}
	return root;
}

Node min_left(Node n){
	if(n==NULL){
		return n;
	}
	while(n->left!=NULL){
		n = n->left;
	}
	return n;
}

Node inorder_successor(Node n){
	if(n->right!=NULL){
		return min_left(n->right);
	}
	else{
		Node p=n->parent;
		while((n!=p->left)&&(p!=NULL)){
			n=p;
                        if (p->parent == NULL) {
                           return NULL;
			p=p->parent;
		}
		return p;
	}
}
void disp(Node root){
	if(root!=NULL){
		disp(root->left);
		cout<<root->data<<"\t";
		disp(root->right);
	}
}
 int main(){
	struct node* root = NULL, *temp, *succ, *min; 
 	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10);   
	root = insert(root, 14);     
  	temp = root->left->left; 
//  	disp(root);
  	Node succ = inorder_successor(temp); 
  	if (succ == NULL) {
		cout<<"-1";
	} else {
		cout<<succ->data;
	}
	
 	return 0;
 }
