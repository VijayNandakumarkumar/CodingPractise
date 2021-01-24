/*

22. Generate Parentheses.

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

vector<string> generateParenthesis(int n) {
      vector<string> v;
        getAllCombinations(n, v, "", 0, 0);
        return v;
    }
        void getAllCombinations(int n, vector<string> &v, string current, int open, int close) {
            if (current.length() == n*2) {
                v.push_back(current);
                return;
            }
            if (open < n) {
               getAllCombinations(n, v, current + "(", open + 1, close) ;
            }
            if (close < open) {
               getAllCombinations(n, v, current + ")", open, close + 1) ;
            }
        }	
