#include<bits/stdc++.h>

using namespace std;

struct trieNode{
	map<char, struct trieNode*> children;
	bool isEndOfWord;
};

typedef struct trieNode* TrieNode;

TrieNode new_node(){
	TrieNode n = new trieNode();
	n->isEndOfWord = false;
}

TrieNode root = new_node();

void insert_node(TrieNode current, string word, int index){
	if(index == word.length())	{
		current->isEndOfWord = true;
		return;
	}
	char ch = word[index];
	TrieNode n = NULL;
	if((current->children).count(ch)){
	 	n = (current->children)[ch];
	}
	if(n==NULL){
		n = new_node();
		(current->children).insert(pair<char, TrieNode> (ch, n));
	}
	current = n;
	insert_node(current, word, index+1);	
}

bool search(TrieNode current, string word, int index){
	if(index == word.length()){
		return current->isEndOfWord;
	}
	char ch = word[index];
	TrieNode n = (current->children)[ch];
	
	if(n==NULL){
		return false;
	}
	return search(n, word, index+1);
}


struct node{
	map<int, int> m;
};

void display_all(map<char, TrieNode> &m){
	map<char, TrieNode>::iterator itr;
	for(itr=m.begin(); itr!=m.end();itr++){
		cout<<itr->first<<"\n";
		display_all(((itr->second)->children));
	}
}

bool delete_trie(TrieNode current, string word, int index){
	if(index==word.length()){
		if(!current->isEndOfWord){
			return false;
		}
		current->isEndOfWord = false;
		return (current->children).size() == 0;
	}
	char ch = word[index];
	TrieNode n = (current->children)[ch];
	if(ch == NULL){
		return false;
	}
	bool shouldDeleteWord = delete_trie(n, word, index+1);
	if(shouldDeleteWord){
		(current->children).erase(ch);
		return (current->children).size() == 0;
	}
	return false;
}

int main(){
	insert_node(root, "abc", 0);
	insert_node(root, "abcd", 0);
//	insert_node(root, "abcde", 0);
	insert_node(root, "abcefgh", 0);
//	insert_node(root, "def", 0);
//	display_all(root->children);
//	bool s = search(root, "abcefgh", 0);
//	cout<<"s = "<<s;
	
	cout<<delete_trie(root, "abcefgh", 0);
	cout<<delete_trie(root, "abcd", 0);
	return 0;
}
