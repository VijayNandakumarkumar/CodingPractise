/*

948. Bag of Tokens

You have an initial power of P, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

 

Example 1:

Input: tokens = [100], P = 50
Output: 0
Explanation: Playing the only token in the bag is impossible because you either have too little power or too little score.

*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        
        int score = 0;
        if ((tokens.size() == 0) || (P < tokens[0])) {
            return 0;
        }
        int i = 0, j = tokens.size() - 1;
        int maxScore = 0;
        while(i<=j) {
            if (P >= tokens[i]) {
                score++;
                P -= tokens[i];
                i++;
            } else if (score > 0) {
                score--;
                P += tokens[j];
                j--;
            }
            if (score > maxScore) {
                maxScore = score;
            }
        }
        return maxScore;
    }
};
