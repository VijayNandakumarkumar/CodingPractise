/**
3. Longest Substring Without Repeating Characters.
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
        map<char, int> v;
        string fin_str = "";
        int max = 0;	
		
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
				if (v[s[j]]==0){
                    v[s[j]]++;
                    fin_str += s[j];
                } else {
                    if (fin_str.length() > max) {
                        max = fin_str.length();
                        fin_str = "";
                        v.clear();
                    }   
                }
            }
        }
        return max;
    }
    

int main() {
	string s = "pwwkew";
	
	cout<<"The max length of unique substring is "<<lengthOfLongestSubstring(s);
	
	return 0;
}
