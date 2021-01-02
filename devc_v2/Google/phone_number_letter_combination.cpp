/*

17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/


#include<bits/stdc++.h>
using namespace std;

void findAllCombinationsRecursive(vector<string> &result, string digits, string current, int ind, vector<string> &mapping){
	if(ind == digits.length()){
		result.push_back(current);
		return;
	}
	
	string letters = mapping[digits[ind]-'0'];
	int i=0;
	for(i=0;i<letters.length();i++){
		findAllCombinationsRecursive(result, digits, current+letters[i], ind+1, mapping);
	}
}

vector<string> findAllCombinations(string digits){
	vector<string> result;
	if((digits.length()==0)||(digits=="")){
		return result;
	}
	vector<string> mapping;
	mapping.push_back("0");
	mapping.push_back("1");
	mapping.push_back("abc");
	mapping.push_back("def");
	mapping.push_back("ghi");
	mapping.push_back("jkl");
	mapping.push_back("mno");
	mapping.push_back("pqrs");
	mapping.push_back("tuv");
	mapping.push_back("wxyz");
	findAllCombinationsRecursive(result, digits, "", 0, mapping);
}



int main(){
	vector<string> v;
	vector<string>::iterator itr;
	v = findAllCombinations("293");
	for(itr = v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
	}
	return 0;
}
