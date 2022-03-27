/*

299. Bulls and Cows

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

    The number of "bulls", which are digits in the guess that are in the correct position.
    The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"

*/

class Solution {
public:

    // 0 ms solution

    string getHint(string s, string g) {
        
        vector<int> count (10, 0);
        int b=0, c=0;
        for(int i=0; i<s.length(); i++) {
            if (s[i] == g[i]) {
                b++;
            } else {
                if (count[g[i] - '0'] < 0) c++;
                if (count[s[i] - '0'] > 0) c++;
                count[g[i] - '0']++;
                count[s[i] - '0']--;
            }
        }
        
        return to_string(b) + "A" + to_string(c) + "B";
    }

    // 3ms
    string getHint(string s, string g) {
        map<char, set<int>> pos;
        map<char, int> freq;
        map<char, set<int>> rpos;
        for(int i=0; i<s.length(); i++) {
            pos[s[i]].insert(i);
            freq[s[i]]++;
        }
        int b=0, c=0;
        for(int i=0; i<g.length(); i++) {
            char ch = g[i];
            if (freq.count(ch)) {
                if (ch == s[i]) {
                    b++;
                    if (freq[ch] <= 0) {
                        c--;
                    }
                } else {
                    if(freq[ch] > 0) {
                        c++;
                    }
                }
                freq[ch]--;
            }
        }
        
        
        string res = to_string(b) + "A" + to_string(c) + "B";
        return res;
    }
};