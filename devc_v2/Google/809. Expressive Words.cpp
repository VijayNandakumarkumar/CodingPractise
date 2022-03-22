/*

809. Expressive Words

Sometimes people repeat letters to represent extra feeling. For example:

    "hello" -> "heeellooo"
    "hi" -> "hiiii"

In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".

You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.

    For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.

Return the number of query strings that are stretchy.

 

Example 1:

Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.

Example 2:

Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3

*/

class Solution {
public:
    /* Our solution.
    int expressiveWords(string s, vector<string>& words) {
        int i=0, j=0, n=s.length();
        int res=0;
        for(int k=0; k< words.size(); k++) {
            string w=words[k];
            i=0;
            j=0;
            if (w.size() > n)
                continue;
            int broke = 0;
            while(i<n || j<w.size()) {
                if (s[i] != w[j]) {
                    cout<<"Break 1 "<<i<<" "<<j<<endl;
                    broke=1;
                    break;
                }
                int ilen=i, jlen=j;
                while(i<n && s[i] == s[i+1]) {
                    i++;
                }
                i++;
                while(j<w.size() && w[j] == w[j+1]) {
                    j++;
                }
                j++;
                int len1 = i-ilen;
                int len2 = j-jlen;
                if ((len1 != len2 && (len1 < 3)) || len1<len2)  {
                    cout<<"Break 2 "<<i<<" "<<j<<endl;
                    broke=1;
                    break;
                }
            }
            cout<<w<<" ";
            cout<<i<<" "<<j<<endl;
            if (i == n && j == w.size() && !broke) {
                res++;
            }
        }
        return res;
    }
    */
    
    int expressiveWords(string s, vector<string>& words) {
        int i=0, j=0, n=s.length();
        int res=0;
        for(int k=0; k< words.size(); k++) {
            string w=words[k];
            if (check(s, w, n)) {
                res++;
            }
        }
        return res;
    }
    
    bool check(string s, string w, int n) {
        if (w.size() > n)
            return false;
        int i=0, j=0;
        while(i<n && j<w.size()) {
            if (s[i] != w[j]) {
                return false;
            }
            int ilen=i, jlen=j;
            while(i<n && s[i] == s[i+1]) {
                i++;
            }
            i++;
            while(j<w.size() && w[j] == w[j+1]) {
                j++;
            }
            j++;
            int len1 = i-ilen;
            int len2 = j-jlen;
            // cout<<s[i-1]<<" "<<len1<<" "<<len2<<endl;
            if ((len1 != len2 && (len1 < 3)) || len1<len2)  {
                return false;
            }
        }
        // cout<<w<<" ";
        // cout<<i<<" "<<j<<endl;
        return (i == n && j == w.size());
    }
};