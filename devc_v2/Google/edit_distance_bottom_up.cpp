/*
learnt from back to back swe.
72. Edit Distance
Hard

4911

66

Add to List

Share
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

*/




#include <bits/stdc++.h>
using namespace std;
int edit_distance(string s1, int s1_len, string s2, int s2_len, int a[][6]){
	if(s1_len<0){
		return s2_len+1;
	}
	if(s2_len<0){
		return s1_len+1;
	}
	if(a[s1_len][s2_len]!=-1){
		return a[s1_len][s2_len];
	}
	if(s1[s1_len]==s2[s2_len]){
		a[s1_len][s2_len] =  edit_distance(s1, s1_len-1, s2, s2_len-1, a);
	}
	
	else{
		int del=edit_distance(s1, s1_len-1, s2, s2_len, a);
		int ins=edit_distance(s1, s1_len, s2, s2_len-1, a);
		int substitute=edit_distance(s1, s1_len-1, s2, s2_len-1, a);
		a[s1_len][s2_len] = 1+ min(del, min(ins, substitute));
	}
	
	return a[s1_len][s2_len];
}

int main(){
	string s1 = "benyam", s2 =  "ephrem";
	int s1_len = s1.length(), s2_len=s2.length();
	int a[6][6];
	
	for(int i=0;i<s1_len;i++){
		for(int j=0;j<s2_len;j++){
		a[i][j]=-1;
		}
	}
	cout<<edit_distance(s1, s1_len-1, s2, s2_len-1, a);
	
;	return 0;
}
