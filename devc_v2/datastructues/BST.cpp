#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* root;

typedef struct node* Node;


Node new_node(int data){
	Node n = (Node)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insert(int data){
	Node n = new_node(data);
	if(root == NULL){
		root = n;
		return;
	}
	
	Node current = root;
	Node parent = NULL;
	while(current!=NULL){
		parent=current;
		if(parent->data<data){
			current = current->right;
			if(current == NULL){
				parent->right = n;
				return;
			}
		}
		else if(parent->data>data){
			current=current->left;
			if(current == NULL){
				parent->left = n;
				return;
			}
		}
	}
}

Node search(int data){
	Node current = root;
	
	while(current!=NULL){
		if(current->data==data){
			cout<<"Found";
			return current;
		}
		else if(current->data>data){
			current=current->left;
		}
		else{
			current=current->right;
		}
	}
	cout<<"Node Found";
	return NULL;
}

void inorder(Node root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void preorder(Node root){
	if(root!=NULL){
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}




int main(){
	int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }            

   printf("\nPreorder traversal: ");
   preorder(root);

   printf("\nInorder traversal: ");
   inorder(root);

   printf("\nPost order traversal: ");
   postorder(root);       

	return 0;
}
