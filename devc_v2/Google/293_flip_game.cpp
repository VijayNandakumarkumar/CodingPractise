/*

293. Flip Game

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

Example:

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]

*/


//Solution-1

vector<string> generatePossibleNextMoves(string s) {
        
        vector <string>res;
        size_t pos = 0;
        
        while (pos < s.size() && pos != string::npos) {
            pos = s.find("++", pos);
            if (pos != string::npos) {
                string tmp (s);
                tmp[pos] = '-';
                tmp[pos+1] = '-';
                res.push_back(tmp);
                ++pos;
            }
        }
        
        return res;
}

//Solution-2

vector<string> generatePossibleNextMoves(string s) {

if ((s.length() == 0) || (s.length() == 1)) {
            return {};
        }
        vector<string> possibilities;
        int i = 0;
        while(i+1 < s.length()) {
            if (s[i] == '+') {
                if (s[i+1] == '+') {
                    string temp = s;
                    temp[i] = '-';
                    temp[i+1] = '-';
                    possibilities.push_back(temp);
                } else {
                    i++;
                }
            }
            i++;
        }
        return possibilities;
    }
};

}
