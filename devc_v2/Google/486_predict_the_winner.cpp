/*

486. Predict the Winner

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:

Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.

*/

//Tushar Roy.
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        } else if (nums.size() == 0) {
            return false;
        }
        pair<int, int> zeroPair {0, 0};
        vector<vector<pair<int, int>>> dp (nums.size(), vector<pair<int, int>> (nums.size(), zeroPair));
        for(int i = 0; i< nums.size();i++) {
            dp[i][i].first = nums[i];
        }
        
        for (int i = 0; i<nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                 cout<<dp[i][j].first<<dp[i][j].second<<"\t";  
            }
            cout<<"\n";
        }
        
        for (int l = 2; l<= nums.size(); l++) {
            for (int i = 0; i <= nums.size() - l; i++) {
                int j = i + l - 1;
                if (nums[i] + dp[i + 1][j].second > nums[j] + dp[i][j-1].second) {
                    cout<<"Came here 1 ";
                    dp[i][j].first = nums[i] + dp[i + 1][j].second;
                    dp[i][j].second = dp[i + 1][j].first;
                    cout<<dp[i][j].first<<dp[i][j].second<<"\n";  
                } else {
                    cout<<"Came here 2 ";
                    dp[i][j].first = nums[j] + dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                    cout<<dp[i][j].first<<dp[i][j].second<<"\n";  
                }
            }
        }
        cout<<dp[0][nums.size() - 1].first<<" "<<dp[0][nums.size() - 1].second;
        if (dp[0][nums.size() - 1].first >= dp[0][nums.size()-1].second)
            return true;
        return false;
        
    }
};
