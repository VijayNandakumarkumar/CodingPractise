/*
3889. Mirror Frequency Distance

You are given a string s consisting of lowercase English letters and digits.

For each character, its mirror character is defined by reversing the order of its character set:

For letters, the mirror of a character is the letter at the same position from the end of the alphabet.
For example, the mirror of 'a' is 'z', and the mirror of 'b' is 'y', and so on.
For digits, the mirror of a character is the digit at the same position from the end of the range '0' to '9'.
For example, the mirror of '0' is '9', and the mirror of '1' is '8', and so on.
For each unique character c in the string:

Let m be its mirror character.
Let freq(x) denote the number of times character x appears in the string.
Compute the absolute difference between their frequencies, defined as: |freq(c) - freq(m)|
The mirror pairs (c, m) and (m, c) are the same and must be counted only once.

Return an integer denoting the total sum of these values over all such distinct mirror pairs.

 

Example 1:

Input: s = "ab1z9"

Output: 3

Explanation:

For every mirror pair:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
a	z	1	1	0
b	y	1	0	1
1	8	1	0	1
9	0	1	0	1
Thus, the answer is 0 + 1 + 1 + 1 = 3.

Example 2:

Input: s = "4m7n"

Output: 2

Explanation:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
4	5	1	0	1
m	n	1	1	0
7	2	1	0	1
Thus, the answer is 1 + 0 + 1 = 2.​​​​​​​

Example 3:

Input: s = "byby"

Output: 0

Explanation:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
b	y	2	2	0
Thus, the answer is 0.

 

Constraints:

1 <= s.length <= 5 * 105
s consists only of lowercase English letters and digits.

*/


class Solution {
public:
    // Another solution from discussion
    int mirrorFrequency(string s) {
        int ans = 0;
        vector<int> freq(128, 0);

        for (char c: s) {
            freq[c]++;
        }

        for(char c: s) {
            if (freq[c] == -1) continue;
            char mirror;
            if (isdigit(c)) {
                mirror = '9' - (c - '0');
            } else {
                mirror = 'z' - (c - 'a');
            }
            ans += abs(freq[c] - freq[mirror]);
            freq[c] = -1;
            freq[mirror] = -1;
        }
        
        return ans;
    }

    
    // My solution
    // int mirrorFrequency(string s) {
    //     map<char, int> freqChar;
    //     map<char, int> freqDigit;
    //     int total = 0;

    //     for (int i=0; i<s.length(); i++) {
    //         int ch = static_cast<int>(s[i]);
    //         if (isdigit(s[i])) {
    //             freqDigit[s[i]]++;
    //             continue;
    //         }
    //         freqChar[s[i]]++;
    //     }

    //     for (int i=0; i<s.length(); i++) {
    //         int chFreq = 0, mirFreq = 0;
    //         int ch = static_cast<int>(s[i]);
    //         if (isdigit(s[i])) {
    //             chFreq = freqDigit[s[i]];
    //             int mir = (57 - ch) + 48;
    //             mirFreq = freqDigit[(char)mir];
    //             freqDigit[s[i]] = 0;
    //             freqDigit[(char)mir] = 0;
    //         } else {
    //             chFreq = freqChar[s[i]];
    //             int mir = (122 - ch) + 97;
    //             mirFreq = freqChar[(char)mir];
    //             freqChar[s[i]] = 0;
    //             freqChar[(char)mir] = 0;
    //         }
    //         total += abs(chFreq - mirFreq);
    //     }
    //     return total;
    // }
};


