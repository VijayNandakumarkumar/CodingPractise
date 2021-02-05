/*

844. Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

*/


// Solution 1: Optimal (no staxk space)

bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;
        while(i >= 0 || j >= 0) {
        while (i >= 0) { 
            if (S[i] == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
        }
        
        while (j >= 0) { // Find position of next possible char in build(T)
                if (T[j] == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
        if ((i>=0) && (j>=0) && (S[i] != T[j]))
            return false;
        if ((i>=0) != (j>=0))
            return false;
        i--;j--;
    }
    return true;
    }

// Solution 2: SubOptimal

bool backspaceCompare(string S, string T) {
        stack<char> s_o;
        stack<char> s_t;
        
        for(int i = 0;i<S.length();i++) {
            if ((S[i] == '#')) {
                 if (!s_o.empty())
                    s_o.pop();
            } else {
                s_o.push(S[i]);
            }
        }
        
        for(int i = 0;i<T.length();i++) {
            if ((T[i] == '#')) {
                 if (!s_t.empty())
                    s_t.pop();
            } else {
                s_t.push(T[i]);
            }
        }
        if (s_o.size() != s_t.size()) {
            return false;
        } else {
            while(!s_o.empty()) {
                if (s_o.top() != s_t.top()) {
                    return false;
                }
                s_o.pop();
                s_t.pop();
            }
        }
     return true;   
    }
