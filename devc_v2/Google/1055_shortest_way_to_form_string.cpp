/*

1055. Shortest Way to Form String.

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

*/

//Solution: O(n)

class Solution {
public:
    int shortestWay(string source, string target) {
        int minSub = 0;
        string remaining = target;
        while(remaining.length() > 0) {
            string subsequence = "";
            int i = 0;
            int j = 0;
            while(i<source.length() && j<remaining.length()) {
                if (source[i++] == remaining[j]) {
                    subsequence += remaining[j++];
                }
            }
            if (subsequence.length() == 0) {
                return -1;
            }
            minSub++;
            remaining = remaining.substr(subsequence.length(), remaining.length());
        }
        return minSub;
    }
};
