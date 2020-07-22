/**

676. Implement Magic Dictionary
Medium

584

135

Add to List

Share
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False

*/

#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

struct trieNode {
	map<char, trieNode*> children;
	bool isEOF;
};

typedef struct trieNode* TrieNode;

TrieNode new_node() {
	TrieNode n = new trieNode();
	n->isEOF = false;
}

TrieNode root = new_node();

void insertRecursive(TrieNode current, string word, int index) {
	if (index == word.length()) {
		current->isEOF = true;
		return;
	}
	
	char ch = word[index];
	TrieNode n = NULL;
	
	if ((current->children).count(ch)) {
		n = (current->children)[ch];
	}
	
	if (n == NULL) {
		n = new_node();
		(current->children).insert({ch, n});
	}
	
	insertRecursive(n, word, index+1);

}

bool searchRecursive(TrieNode current, string word, int index, int replaceAttemptLeft) {
	if (index == word.length()) {
		return current->isEOF;
	}
	char ch = word[index];
	TrieNode n = (current->children)[ch];
	
	if (n == NULL) {
		if (replaceAttemptLeft == 0) {
			return false;	
		} else {
			replaceAttemptLeft--;
			map<char, TrieNode>::iterator it;
			int i = 0;
			for (i = 0, it=(current->children).begin(); it!=(current->children).end()&&i<(current->children).size() - 1; it++, i++) {
				if (searchRecursive(it->second, word, index + 1, replaceAttemptLeft)) {
					return true;
				}
			}
			return false;
		}
	}
	
	return searchRecursive(n, word, index + 1, replaceAttemptLeft);
	
}


int main() {
	
	vector<string> words = {"heooo", "hai", "hellp", "leetcode"};
	vector<int> wordLengths;
	string searchWord = "hhllp";
	
	for (int i=0; i<words.size(); i++) {
		insertRecursive(root, words[i], 0);
		wordLengths.push_back(words[i].length());
	}
	
	if (!(count(wordLengths.begin(), wordLengths.end(), searchWord.length()))) {
		cout<<"No word of length of search word in the dictionary";
		return 0;
	}
	cout<<"The result of recursive replacement search in the dict is "<<searchRecursive(root, searchWord, 0, 1);
	
	
	return 0;
}
