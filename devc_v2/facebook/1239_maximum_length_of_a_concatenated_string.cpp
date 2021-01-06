/*

1239. Maximum Length of a Concatenated String with Unique Characters

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.

*/


#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node* left, *right;
};


typedef struct node* Node;

bool isUnique(string s) {
        vector<int> v(26, 0);
        for (int i = 0;i<(int)s.size();i++) {
            if (v[s[i] - 'a']) {
                return false;
            }
            v[s[i] - 'a']++;
        }
        return true;
    }
    
    void maxLengthConStr(vector<int>& result, vector<string>& arr, int ind, string str) {
        if (ind == arr.size() && isUnique(str) && str.length() > result[0]) {
             result[0] = str.length();
            return;
        }
        if (ind == arr.size()) {
            return ;
        }
        maxLengthConStr(result, arr, ind + 1, str);
        maxLengthConStr(result, arr, ind  + 1, str + arr[ind]);  
    } 

int maxLength(vector<string>& arr) {
        vector<int> result (1, 0);
        if (arr.size() == 0) {
            return 0;
        }
        if (arr.size() == 1) {
            return isUnique(arr[0]) ? arr[0].length() : 0;
        }
        maxLengthConStr(result, arr, 0, "");
        return result[0];
    }
    
int main(){
	vector<string> str {"un","iq","ue"};
	cout<<maxLength(str);
	return 0;
}
