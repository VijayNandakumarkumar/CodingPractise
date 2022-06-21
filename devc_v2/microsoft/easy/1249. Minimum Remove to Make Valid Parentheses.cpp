/*

1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

*/


// C++ - disc

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> pos;
        set<int> posToRem;
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                pos.push(i);
            } else if (s[i] == ')') {
                if (pos.empty()) {
                    posToRem.insert(i);
                    continue;
                }
                pos.pop();
            }
        }
        while(!pos.empty()) {
            posToRem.insert(pos.top());
            pos.pop();
        }
        cout<<"Set to remove size - "<<posToRem.size();
        string ans = "";
        for (int i=0; i<s.length(); i++) {
            if (posToRem.find(i) != posToRem.end()) {
                continue;
            }
            ans += s[i];
        }
        
        return ans;
    }
};

// Java

class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> pos = new Stack<>();
        Set<Integer> posToRem = new HashSet<>();
        
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                pos.push(i);
            } else if (c == ')') {
                if (pos.isEmpty()) {
                    posToRem.add(i);
                    continue;
                }
                pos.pop();
            }
        }
        
        while(!pos.isEmpty()) {
            posToRem.add(pos.peek());
            pos.pop();
        }
        System.out.println("set size " + posToRem.size());
        String ans = "";
        for(int i=0; i<s.length(); i++) {
            if (posToRem.contains(i)) {
                continue;
            }
            ans += s.charAt(i);
        }
        return ans;
    }
}