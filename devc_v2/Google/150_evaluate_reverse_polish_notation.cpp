/*

150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

#include<ctype.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) {
            return 0;
        } else if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        stack<int> s;
        int n = tokens.size();
        int res = 1;
        set<string> op {"+", "-", "*", "/"};
        for(int i=0; i<n; i++) {
            if (isSign(tokens[i])) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                res = compute(tokens[i], a, b);
                s.push(res);
                cout<<res;
            } else {
                s.push(stoi(tokens[i]));
            } 
        }
        return res;
    }
    
    bool isSign(string s)                                               {
        if(s == "+" || s == "-" || s == "*" || s == "/") return true    ;
        return false                                                    ;}
    
    int compute(string s, int a, int b) {
        
        if(s == "+") {
            return b+a;
        } else if (s == "-") {
            return b-a;
        } else if (s == "*") {
            return b*a;
        } else if (s == "/") {
            return b/a;
        }
        return 0;
    }
};