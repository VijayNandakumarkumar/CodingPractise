/**
720. Longest Word in Dictionary
Easy

622

735

Add to List

Share
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

*/

// Set solution

string longestWord(vector<string>& words) {
        set<string> s (words.begin(), words.end());
        string st = "";
        int maxlen = 0;
        for (string word : words) {
            string substr = "";
            for (int i = 0; i<word.length(); i++) {
                substr += word[i];
                if(s.find(substr) == s.end()) {
                    break;
                }
            }
            if (substr.compare(word) == 0) {
                if (word.length() > maxlen) {
                    st = word;
                    maxlen = word.length();
                } else if (word.length() == maxlen) {
                    vector<string> s1 {st};
                    vector<string> s2 {word};
                    if (lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) == false) {
                        st = word;
                        maxlen = word.length();
                    }
                }
                
            }
        }
        return st;
    }


// trie solution

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

bool searchRecursiveLetterByLetter(TrieNode current, string word, int index) {
	if (index == word.length()) {
		return current->isEOF;
	}
	char ch = word[index];
	TrieNode n = (current->children)[ch];
	
	if (n == NULL) {
		return false;
	}
	
	if (!(n->isEOF)) { //each letter is a word here so EOF must be true for each letter.
		return false;
	}
	
	return searchRecursiveLetterByLetter(n, word, index + 1);
	
}


int main() {
	vector<string> s  {"a", "banana", "app", "appl", "ap", "apply", "apple"};
	int maxLen = 0, index = 0;
	for (int i=0; i<s.size(); i++) {
		cout<<s[i]<<"\n";
		insertRecursive(root, s[i], 0);	
	}
	
	for (int i=0; i<s.size(); i++) {
		if (searchRecursiveLetterByLetter(root, s[i], 0)) {
			if (s[i].length() > maxLen) {
				maxLen = s[i].length();
				index = i;
			} 
			else if (s[i].length() == maxLen) {
				vector<string> s1 {s[index]};
				vector<string> s2 {s[i]};
				if ((lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end())) == false) {
					maxLen = s[i].length();
					index = i;
				}
			}
		}
	} 
	cout<<"The longest string is "<<s[index];
	return 0;
}
