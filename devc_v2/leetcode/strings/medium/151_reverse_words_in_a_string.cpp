/*

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"

*/


class Solution {
public:
    string reverseWords(string s) {
        string WHITESPACE = " \n\r\t\f\v";
        reverse(s.begin(), s.end());
        s.insert(s.end(), ' ');
        int j=0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
                while(s[j] == ' ') {
                    s.erase(s.begin()  + j);
                }
            }
        }
        s.erase(0, s.find_first_not_of(WHITESPACE));
        s.erase(s.find_last_not_of(WHITESPACE) + 1);
        return s;
    }
};
