/*

294. Flip Game II

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

*/

class Solution {
public:
    bool canWin(string s) {
        
        if ((s.length() == 0) || (s.length() == 1)) {
            return false;
        }
        
        size_t pos=0;
        while (pos < s.size() && pos != string::npos) {
            pos = s.find("++", pos);
            if (pos != string::npos) {
                string temp (s);
                temp[pos] = '-';
                temp[pos+1] = '-';
                if (!canWin(temp)) {
                    return true;
                }
                pos++;
            }
        }
        return false;
    }
};
