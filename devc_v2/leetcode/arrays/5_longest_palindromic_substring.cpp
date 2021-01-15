/*

5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

*/


string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int start = 0, end = 0;
        int len = 0;
        for(int i = 0;i<s.length();i++) {
            int len1 = expandToCentre(s, i, i);
            int len2 = expandToCentre(s, i, i+1);
            len = max(len1, len2);
            if (len > (end - start)) {
                start = i - ((len- 1) /2);
                end = i + (len/2);
            }
        }
        return sub_str(s, start, end + 1);
        
    }
    int expandToCentre(string s, int left, int right) {
        if (left>right) {
            return 0;
        }
        while(left>=0 && right < s.length() && (s[left] == s[right])) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string sub_str(string s, int left, int right) {
        string str = "";
        for (int i = left;i < right; i++) {
            str += s[i];
        }
        return str;
    }string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int start = 0, end = 0;
        int len = 0;
        for(int i = 0;i<s.length();i++) {
            int len1 = expandToCentre(s, i, i);
            int len2 = expandToCentre(s, i, i+1);
            len = max(len1, len2);
            if (len > (end - start)) {
                start = i - ((len- 1) /2);
                end = i + (len/2);
            }
        }
        return sub_str(s, start, end + 1);
        
    }
    int expandToCentre(string s, int left, int right) {
        if (left>right) {
            return 0;
        }
        while(left>=0 && right < s.length() && (s[left] == s[right])) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string sub_str(string s, int left, int right) {
        string str = "";
        for (int i = left;i < right; i++) {
            str += s[i];
        }
        return str;
    }
