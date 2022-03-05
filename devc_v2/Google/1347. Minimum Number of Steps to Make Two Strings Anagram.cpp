/*

1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

*/

class Solution {
public:
    int minSteps(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        map<char, int> lStr, rStr;
        set<char> lSet;
        int n = s.length();
        for(int i=0; i<n; i++) {
            lStr[s[i]]++;
            rStr[t[i]]++;
            lSet.insert(s[i]);
        }
        int res = 0;
        for(auto it=lSet.begin(); it!=lSet.end(); it++) {
            int lCount = lStr[*it];
            int rCount = rStr[*it];
            if (rCount < lCount) {
                res += lCount - rCount;
            }
        }       
        return res;
    }
};