/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.length();
        if (slen == 0) {
            return "";
        }
        int start = 0, end =0, maxlen=0;
        for (int i=0; i<slen; i++) {
            int len1 = expandToCenter(s, i, i);
            int len2 = expandToCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > (end - start)) {
                start = i - (len -1)/2;
                end = i + (len)/2;
            }
        }
        
        return sub_str(s, start, end+1);
    }
    int expandToCenter(string s, int left, int right) {
        if (left>right) {
            return 0;
        }
        while(left >= 0 && right < s.length() && (s[left] == s[right])) {
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
};
// @lc code=end

