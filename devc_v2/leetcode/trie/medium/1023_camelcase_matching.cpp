1023. Camelcase Matching

A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".


class Solution {
public:
    
    struct trieNode {
        map<char, trieNode*> children;
        bool isEOF;
    };

    typedef struct trieNode* TrieNode;

    TrieNode new_node() {
        TrieNode n = new trieNode();
        n->isEOF = false;
        return n;
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
    
    bool searchRecursive(TrieNode current, string word, int index) {
        if (word.length() == 0) {
            return false;
        }
        if (word.length() == index) {
            return current->isEOF;
        }
        
        char ch = word[index];
        TrieNode n = NULL;
        if ((current->children).count(ch)) {
            n = (current->children)[ch];
        }
        if (n == NULL) {
            if (isupper(ch)) {
                return false;
            } else {
                while((islower(ch)) && (index < word.length()) && !((current->children).count(ch))) {
                    index += 1;
                    ch = word[index];
                }
                return searchRecursive(current, word, index);
            }
        }
        return searchRecursive(n, word, index+1);
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> matches(queries.size(), false);
        insertRecursive(root, pattern, 0);
        
        for (int i=0;i<queries.size();i++) {
            matches[i] = searchRecursive(root, queries[i], 0);
        }
        return matches;
    }
};
