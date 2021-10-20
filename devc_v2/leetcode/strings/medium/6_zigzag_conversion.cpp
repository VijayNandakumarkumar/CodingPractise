/*

6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/

My Solution: Worked out in Note 7.

class Solution {
public:
    string convert(string str, int numRows) {
        //numRows == row
        //Colums inbetween == numRows - 2
        //IC (constant to be added) == numsRows + (numRows - 2)
        //Diagoal == j - (i*2)
        if ((numRows == 1) || (numRows >= str.length())) {
            return str;
        }
     int len = str.length();
     int ic = numRows + (numRows - 2);
        string s = "";
        int j = 0;
    for (int i = 0; i<numRows; i++) {
        s.push_back(str[i]);
        j = i + ic;
        if ((i == 0) || (i == (numRows - 1))) {
            while(j < len) {
                // cout<<str[j]<<" ";
                s.push_back(str[j]);
                j += ic;
            }
        } else {
            while(j < len) {
                s.push_back(str[j - (i*2)]);
                s.push_back(str[j]);
                j += ic;
            }
            if ((j >= len) && ((j - (i*2)) < len)) {
                s.push_back(str[j - (i*2)]);
            }
            
        }
    }
        return s;
    }
};