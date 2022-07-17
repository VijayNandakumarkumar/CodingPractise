/*

1100. Find K-Length Substrings With No Repeated Characters

Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.

 

Example 1:

Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: s = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.


*/

class Solution {
public:
    // Beloe one is much more efficient - this because it avoid clearinng out the entire set every time.
    
    /*
    int numKLenSubstrNoRepeats(string s, int k) {
        if ((k>s.length()) || (k==0) || (s.length()==0)) {
            return 0;
        } else if (k==1) {
            return s.length();
        }
        set<char> st;
        int res = 0;
        int len = s.length() - k + 1;
        string temp = "";
        bool found = true;
        for (int i=0; i<len; i++) {
            found = true;
            st.clear();
            temp = "";
            
            for (int j=i; j<i+k; j++) {
                if (st.find(s[j]) != st.end()) {
                    found = false;
                    break;
                }
                st.insert(s[j]);
                temp+=s[j];
            }
            if (found && temp.length() == k) {
                res++;
            }
        }
        return res;
    } */
    
    
    int numKLenSubstrNoRepeats(string s, int k) {
        if ((k>s.length()) || (k==0) || (s.length()==0)) {
            return 0;
        } else if (k==1) {
            return s.length();
        }
        set<char> st;
        int res = 0;
        int len = s.length();
        string temp = "";
        bool found = true;
        int startInd = 0;
        for (int i=0; i<len; ) {
            found = true;
            if (st.size() == k) {
                res++;
                st.erase(s[startInd++]);
            }
            if (st.find(s[i]) != st.end()) {
                st.erase(s[startInd++]);
                continue;
            }
            st.insert(s[i]);
            i++;
        }
        if (st.size() == k) res++;
        return res;
    }
};