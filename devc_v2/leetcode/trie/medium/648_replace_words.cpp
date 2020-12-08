648. Replace Words
Medium

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Example 3:

Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"

Example 4:

Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"


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
            // cout<<"\n";
            return;
        }

        char ch = word[index];
        TrieNode n = NULL;

        if ((current->children).count(ch)) {
            n = (current->children)[ch];
        }

        if (n == NULL) {
            // cout<<ch;
            n = new_node();
            (current->children).insert({ch, n});
        }

        insertRecursive(n, word, index+1);

    }
    
    string searchRecursive(TrieNode current, string word, int index) {
        if ((word.length() == 0) || (word.length() == index)) {
            return word;
        }
        if (current->isEOF == true && index > 0) {
            return word.substr(0, index);
        }
        char ch = word[index];
        TrieNode n = NULL;
        if ((current->children).count(ch)) {
            n = (current->children)[ch];
        }
        if (n == NULL) {
            return word;
        }
        return searchRecursive(n, word, index+1);
    }
    
     string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0; i<dictionary.size(); i++) {
            insertRecursive(root, dictionary[i], 0);
        }
         string masterstring = "";
         string blank = " ";
         string sub = "";
         for(int i = 0; i<sentence.size(); i++) {
             if (sentence[i] == ' ') {
                masterstring += searchRecursive(root, sub, 0);
                 masterstring += blank;
              sub = "";
              continue;
          } else {
              sub += sentence[i];
          }
         }
         if (sub.compare(blank) != 0) {
                 masterstring += searchRecursive(root, sub, 0);
             sub = "";
             }
         return masterstring;
    }

};
