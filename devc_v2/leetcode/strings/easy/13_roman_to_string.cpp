/*

13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4
Example 3:

Input: s = "IX"
Output: 9
Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        stack<char> st;
        int sum=0;
        for (int i = 0;i<len;i++) {
            int val = getVal(s[i]);
            sum += val;
            if  ((! st.empty()) && (getPrecedence(st.top()) < getPrecedence(s[i])))             {
                sum -= 2 * getVal(st.top());
                st.pop();
            }
        
            st.push(s[i]);
        }
        return sum;
    }
    
    int getPrecedence(char ch) {
        switch(ch) {
            case 'M':
                return 7;
            case 'D':
                return 6;
            case 'C':
                return 5;
            case 'L':
                return 4;
            case 'X':
                return 3;
            case 'V':
                return 2;
            case 'I':
                return 1;
            default:
                cout<<"Not a valid romman number";
                return 0;
        }
    }
    
    int getVal(char ch) {
        switch(ch) {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                cout<<"Not a valid romman number";
                return 0;
        }
    }
};