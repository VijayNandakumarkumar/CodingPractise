/*

1048. Longest String Chain

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5

*/


Solution: Similar to longest increasing seq.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int count = 1;
        int len = words.size();
        auto comp = [](string a, string b) {
            return a.length() < b.length();
        };
        sort(words.begin(), words.end(), comp);
        // for (int i = 0;i<words.size();i++) {
        //     cout<<words[i]<<" ";
        // }
        map<string, set<string>> m;
        vector<int> dp (len, 1);
        for (int i = 1; i < len; i++) {
            for(int j = 0;j<i;j++) {
                if (is_predecessor(words[i],words[j])) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            count = max(count, dp[i]);
        }
        return count;
       }
    
    bool is_predecessor(string& big, string& small) {
        int len1 = big.length();
        int len2 = small.length();
        if (len1 - 1 != len2) {
            return false;
        } 
        int i = 0, j = 0, time = 0;
        while(i < big.size()) {
            if(j == small.size()) {
                return true;
            }
            if(big[i] == small[j]) {
                i++; j++;
            }
            else {
                time++;
                if(time == 2)
                    return false;
                i++;
            }
        }
        return true;
    }
    
    
    
    
};
