/*

1153. String Transforms Into Another String

Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

 

Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.

*/


class Solution {
public:
    bool canConvert(string str1, string str2) {
        set<char> s;
        map<char,char> m;
        for (int i = 0; i<str1.length(); i++) {
            s.insert(str2[i]);
            if ((m.count(str1[i]) > 0) && (m[str1[i]] != str2[i])) {
               return  false;
            }
            m.insert({str1[i], str2[i]});
        }
        if ((str1.compare(str2) != 0) && (m.size() == 26) && (s.size() == 26)) {
            return false;
        }
        return true;
    }
};
