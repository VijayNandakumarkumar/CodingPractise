/*

794. Valid Tic-Tac-Toe State

Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.

Here are the rules of Tic-Tac-Toe:

    Players take turns placing characters into empty squares ' '.
    The first player always places 'X' characters, while the second player always places 'O' characters.
    'X' and 'O' characters are always placed into empty squares, never filled ones.
    The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.

 

Example 1:

Input: board = ["O  ","   ","   "]
Output: false
Explanation: The first player always plays "X".

Example 2:

Input: board = ["XOX"," X ","   "]
Output: false
Explanation: Players take turns making moves.

Example 3:

Input: board = ["XOX","O O","XOX"]
Output: true

*/

class Solution {
public:
    /* 0ms from discussion
    bool validTicTacToe(vector<string>& board) {
        int playerOneMoves=0,playerTwoMoves=0;
        for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                        //check current char and increase the playerMove Count respectively
                        char currentChar=board[i][j];
                        if(currentChar==' ')
                                continue;
                        currentChar=='X'?playerOneMoves++:playerTwoMoves++;
                }
        }

        //This case can't happen in a valid game as playerOne is making the first move
        if(playerTwoMoves>playerOneMoves)
                return false;

        //playerOne can be atmost 1 move ahead of playerTwo
        if(playerOneMoves-1>playerTwoMoves)
                return false;

        //both have make equal number of moves to reach here.
        //so last move would have been made by playerTwo and it would be valid only if playerOne hasn't won the game till that point.
        if(playerOneMoves==playerTwoMoves) {
                //for this to happen playerOne must not have win the game in previous moves
                if(hasWon('X',board)) return false;
                return true;

        }

        //playerOne is 1 move ahead of playerTwo again that would only be possible if playerTwo hadn't won the game
        //in this previous move.
        if(playerOneMoves-1==playerTwoMoves) {
                // for playerOne to make his most recent move playerTwo must not have won in previous moves
                if(hasWon('O',board)) return false;
                return true;
        }
        return false;
}

// check is player has won the game or not.
bool hasWon(char player,vector<string>&board){

        int count=0;
        //checking each row
        for(int i=0; i<3; i++) {
                int count=0;
                for(int j=0; j<3; j++) {
                        if(board[i][j]==player)
                                count++;
                }
                if(count==3)
                        return true;
        }

        //checking in coloumn
        for(int i=0; i<3; i++) {
                int count=0;
                for(int j=0; j<3; j++) {
                        if(board[j][i]==player)
                                count++;
                }
                if(count==3)
                        return true;
        }

        //check both diagnols
        if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)
                return true;

        if(board[2][0]==player&&board[1][1]==player&&board[0][2]==player)
                return true;

        return false;
}*/
	// Our solution
    bool validTicTacToe(vector<string>& board) {
        
        unordered_map<string, int> freq;
        int countX = 0, countO = 0;
        bool winX = false, winY = false;
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                string s = "";
                s+=board[i][j];
                if (s == " ") {
                    continue;
                }
                if (s == "X") {
                    countX++;
                } else if (s == "O") {
                    countO++;
                }
                
                string rstring = "("+to_string(i)+")"+ s;
                string cstring = s + "(" + to_string(j) +")";
                string dstring1 = "d" + s;
                string dstring2 = s + "d";
                freq[rstring]++;
                freq[cstring]++;
                if (i==j) {
                    freq[dstring1]++;
                    if (i==1)
                        freq[dstring2]++;
                } else if (i+j - 2 == 0) {
                    freq[dstring2]++;
                }
                if (freq[rstring] == 3 || freq[cstring] == 3 || freq[dstring1] == 3 || freq[dstring2] == 3) {
                    if (s == "X") {
                        winX = true;
                    } else {
                        winY = true;
                    }
                }
            }
        }
        if (countO > countX 
            || (countX-1 > countO) 
            || (countX == countO && winX)
            || (countX-1 == countO && winY)) {
            return false;
        }
        return true;
    } 
};