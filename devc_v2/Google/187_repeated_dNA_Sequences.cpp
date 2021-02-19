/*

187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     int i = 0, j = 0;
        map<string, int>m;
        vector<string> v;
        while (i+10 <= s.length()) {
            string temp = s.substr(i, 10);
            m[temp]++;
            if (m[temp] == 2){
                v.push_back(temp);
            }
            i++;
        }
        return v;
    }
};
