#include<bits/stdc++.h>
using namespace std;

struct Tree{
	int val;
	struct Tree* left;
	struct Tree* right;
};

struct Tree* NewNode(int val){
	struct Tree* node = (struct Tree*)	malloc(sizeof(struct Tree));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Tree* sortedArrayToBst(vector<int>& arr, int start, int end){
	if(start>end){
		return NULL;
	}
	int mid = (start+end)/2;
	struct Tree* root = NewNode(arr[mid]);
	
	root->left =  sortedArrayToBst(arr, start, mid-1);
	root->right = sortedArrayToBst(arr, mid+1, end);
	
	return root;
}

void preOrderTraversal(struct Tree* root){
	if(root==NULL){
		return;
	}
	printf("%d", root->val);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

int isLeaf(struct Tree* node){
	return node->left==NULL && node->right==NULL;
}

void addLeaves(struct Tree* node, vector<int>& res){
	if(isLeaf(node)){
		res.push_back(node->val);
	}
	else{
		if(node->left!=NULL)
			addLeaves(node->left, res);
		if(node->right!=NULL){
			addLeaves(node->right, res);
		}
	}
	return;
}

vector<int> getBoundary(struct Tree* node){

	vector<int> res;
	
	if(node==NULL){
		return res;
	}
	
	if(!isLeaf(node)){
		res.push_back(node->val);
	}
	
	struct Tree* t = node->left;
	
	while(t!=NULL){
		if(!isLeaf(t)){
			res.push_back(t->val);
		}
		if(t->left!=NULL){
			t=t->left;
		}
		else{
			t=t->right;
		}
	}
	
	addLeaves(node, res);
	
	stack <int> s;
	
	t = node->right;
	
	while(t!=NULL){
		if(!isLeaf(t)){
			s.push(t->val);
		}
		if(t->right!=NULL){
			t=t->right;
		}
		else{
			t=t->left;
		}
	}
	
	while(!s.empty()){
		res.push_back(s.top());
		s.pop();
	}
	return res;
}

int main(){
	
	vector<int> arr;
	for(int i = 1;i<8;i++){
		arr.push_back(i);
	}
	struct Tree* node = sortedArrayToBst(arr, 0, arr.size()-1);
	preOrderTraversal(node);
	vector<int> res = getBoundary(node);
	vector<int>::iterator itr;
//	for(itr=res.begin();itr<res.end();itr++){
//		cout<<itr;
//	}
cout<<"\n";
	for(int i=0;i<res.size();i++){
		cout<<res[i];
	}
	return 0;	
}
