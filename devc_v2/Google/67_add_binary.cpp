/*

67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

*/

#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        string result;
        int i = a.length() - 1, j = b.length() - 1;
        int carry=0, sum = 0;
        while (i>=0 || j>=0) {
            sum = carry;
            if (i>=0) {sum += a[i--] - '0';}
           if (j>=0) {sum += b[j--] - '0';}
            carry = sum/2;
            result += to_string(sum%2);
        }
        if (carry) {
            result += to_string(carry);
        }
                                
        reverse(result.begin(), result.end());
        return result;
    }

int main() {
   
        cout<<addBinary("111", "101");
    return 0;
}
