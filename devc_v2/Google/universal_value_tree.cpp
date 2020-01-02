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
//bool is_unival(Node root){
//	if(root==NULL){
//		return true;
//	}
//	
//	if((root->left!=NULL)&&(root->left->key!=root->key)){
//		return false;
//	}
//	if((root->right!=NULL)&&(root->right->key!=root->key)){
//		return false;
//	}
//	if((is_unival(root->left))&&(is_unival(root->right))){
//			return true;
//		}
//	return false;
//}
//int total_count = 0;
//int count_unival(Node root){
//	if(root==NULL){
//		return 0;
//	}
//	total_count = count_unival(root->left)+count_unival(root->right);
//	if(is_unival(root)){
//		total_count += 1;
//	}
//	return total_count;
//}

bool count_universal_trees(Node root, int &count){
	if(root == NULL){
		return true;
	}
	
	bool left = count_universal_trees(root->left, count);
	bool right = count_universal_trees(root->right, count);
	if((left==false)||(right==false)){
		return false;
	}
	if((root->left!=NULL)&&(root->left->key!=root->key)){
		return false;
	}
	if((root->right!=NULL)&&(root->right->key!=root->key)){
		return false;
	}
	if((left)&&(right))
	{
		count++;
		return true;
	}
}

int main(){
	Node root = newNode(5);
	root->left = newNode(4); 
    root->right = newNode(5); 
    root->left->left = newNode(4); 
    root->left->right = newNode(4); 
//    root->right->left = newNode(1); 
    root->right->right = newNode(5);
//    display(root);
    cout<<"\n";
//    cout<<count_unival(root);
int countt = 0;
		count_universal_trees(root, countt);
		cout<<countt;
	return 0;
}
