#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node* Nde;

void verticalSumUtil(Nde root, int ind, map<int, int> &mp){
	if(root == NULL){
		return;
	}
	
	mp[ind] += root->data;
	
	verticalSumUtil(root->left, ind-1, mp);
	verticalSumUtil(root->right, ind+1, mp);
	return;
	
}

void verticalSum(Nde root){
	map<int, int> mp;
	
	map<int, int>::iterator it;
	
	verticalSumUtil(root, 0, mp);
	for(it=mp.begin();it != mp.end();it++){
		cout<<it->second<<" ";
	}
}

Nde newNode(int data){
	Nde new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
}

int main(){
	
	Nde n1 = newNode(4);
	Nde n2 = newNode(1);
	Nde n3 = newNode(2);
	n1->left = n2;
	n1->right = n3;
	
	n2->left = newNode(3);
	n2->right = newNode(4);
	n3->left = newNode(6);
	n3->right = newNode(7);
	
	verticalSum(n1);
	return 0;
}
