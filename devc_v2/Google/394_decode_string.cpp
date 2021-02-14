/*

394. Decode String


Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

*/

//Can use stack instead of recursion (recursion uses call stack).

// Solution-1: (O(maxK* n)

class Solution {
public:
    string decodeString(string s) {
        int len = s.length();
        int i = 0;
        string ans = "";
        
        ans = formString(s, i, len);
        return ans;
    }
    
    string formString(string s, int i,int len) {
        string curAns = "";
        
        if (i>=len) {
            return curAns;
        }
        while (i < len) {
            if (isalpha(s[i])) {
                curAns += s[i];
                i++;
            }  else if (isdigit(s[i])) {
                string timeString = findTimes(s, i);
                int times = stoi(timeString);
                i += timeString.length() - 1;
                if (s[i+1]=='[') {
                    int openParam = i+1;
                    int closeParam = openCloseParanthesis(s, openParam);
                    string inParam = formString(s, i+2, closeParam);
                    while (times > 0) {
                        curAns += inParam;
                        times--;
                    }
                    i = closeParam + 1;
                }
            }
        }
        return curAns;
    }
    string findTimes(string s, int i) {
        string times;
        while(isdigit(s[i])) {
            times+=s[i];
            i++;
        }
        return times;
    }
    int openCloseParanthesis(string s, int pos) {
        stack<char> st;
        st.push(s[pos]);
        pos += 1;
        while (!st.empty()) {
            if (s[pos] == ']') {
                st.pop();
                if (st.empty()) {
                    return pos;
                }
            } else if (s[pos] == '[') {
                st.push(s[pos]);
            }
            pos++;
        }
        return -1;
    }
};
