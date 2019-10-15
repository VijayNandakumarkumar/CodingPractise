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

int findClosingIndex(char* str, int start, int end){
	if(start>end){
		return -1;
	}
	stack <char> s;
	for(int i=start;i<=end;i++){
		if(str[i]=='('){
			s.push('(');
		}
		else if(str[i]==')'){
			if(s.top()=='('){
				s.pop();
				if(s.empty()){
					return i;
				}
			}
		}
	}
	return -1;
}

struct Tree* treeFromString(char* str, int start, int end){
	if(start>end){
		return NULL;
	}
	int index = -1;
	
	struct Tree* root= NewNode(str[start]-'0');
	
	if((start+1 < end)&&(str[start+1]=='(')){
		index = findClosingIndex(str, start+1, end);
	}
	if(index != -1){
		
		root->left = treeFromString(str, start+2, index-1);
		root->right= treeFromString(str, index+2, end-1);
	}
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

int main(){
	
	char* str = "4(2(3)(1))(6(5))";
	struct Tree* node = treeFromString(str, 0, 15);
	preOrderTraversal(node);
	return 0;	
}
