/*

792. Number of Matching Subsequences

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

*/

class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(), len = s.length(), res=0;
        map<string, int> prev;
        for(int i=0; i<n; i++) {
            string word = words[i];
            if (prev.count(word)) {
                int val = prev[word];
                if (val== 1) {
                    res+=1;
                    continue;
                } else if (val == 0) {
                    continue;
                }
            }
            int j = 0, k=0;
            while(j<len && k<word.length()) {
                if (s[j] == word[k]) {
                    j++;
                    k++;
                } else {
                    j++;
                }
            }
            if (k==word.length()) {
                prev[word] = 1;
                res+=1;
            } else {
                prev[word] = 0;
            }
        }
        return res;
    }
    
    // Another solution using buckets. But our own solution is better.
    /*
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<string>> dict;
        int n = words.size(), len = s.length(), res=0;
        for (int i=0; i<n; i++) {
            dict[words[i][0]].push_back(words[i]);
        }
        for (int i=0; i<len; i++) {
            vector<string> nwords = dict[s[i]];
            dict.erase(s[i]);
            int m = nwords.size();
            for(int j=0; j<m; j++) {
                string word = nwords[j];
                if (word.length() == 1) {
                    res++;
                } else {
                    word.erase(word.begin());
                    dict[word[0]].push_back(word);
                }
            }
        }
        return res;
    }
    */
};