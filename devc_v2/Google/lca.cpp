#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node* left, *right;
};

typedef struct node* Node;

Node newNode(int key){
	Node n = (Node)malloc(sizeof(struct node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

Node findLca(Node root, int n1, int n2){
	if(root == NULL)
		return NULL;
	if((root->key == n1)||(root->key == n2)){
		return root;
	}
	
	Node left_lca = findLca(root->left, n1, n2);
	Node right_lca = findLca(root->right, n1, n2);
	
	if(left_lca&&right_lca)
		return root;
	return (left_lca!=NULL)? left_lca: right_lca;
	
}

int main(){
	Node root = newNode(1);
	root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);
    
    cout << "\nLCA(4, 5) = " <<findLca(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLca(root, 4, 6)->key; 
    cout << "\nLCA(3, 4) = " << findLca(root, 3, 4)->key; 
    cout << "\nLCA(2, 4) = " << findLca(root, 2, 4)->key; 
	return 0;
}
