/*

412. Fizz Buzz


Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/


vector<string> fizzBuzz(int n) {
        vector<string> stringNums;
        string s = "";
        for (int i = 1;i<=n;i++) {
            s = "";
            if (((i%3) == 0) && ((i%5)==0)) {
                s += "FizzBuzz";
            } else if ((i%5) == 0) {
                s += "Buzz";
            } else if ((i%3) == 0) {
                s += "Fizz";
            } else {
                s = to_string(i);
            }
            stringNums.push_back(s);
        }
        return stringNums;
    }

// Solution:

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> stringNums;
        string s = "";
        for (int i = 1;i<=n;i++) {
            s = "";
            if ((i%3) == 0) {
                s += "Fizz";
            } 
            if ((i%5) == 0) {
                s += "Buzz";
            }
            if(s.empty()) {
                s = to_string(i);
            }
            stringNums.push_back(s);
        }
        return stringNums;
    }
};
