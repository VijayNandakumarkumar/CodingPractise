/*

7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

*/

class Solution {
public:
    int reverse(int x) {
        if (x >= INT_MAX || x <= INT_MIN) {
            return 0;
        }
        bool isNegative = false;
        if (x == 0) {
            return 0;
        } else if (x < 0) {
            isNegative = true;
            x = x * -1;
        }

        int rem = 0;
        long rev = 0;
        while (x!=0) {
            rem = x % 10;
            if ((rev * 10) >= INT_MAX) {
                cout<<" here ";
                return 0;
            }
            rev = (rev * 10) + rem;
            x = x / 10;
        }
        return (isNegative) ? rev * -1 : rev;
    }
};
