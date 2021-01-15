int longestCommonSubsequence(string text1, string text2) {
        int row = text1.length();
        int col = text2.length();
        vector<vector<int> > dp(row + 1, vector<int> (col + 1, 0));
       
        int maxlen = 0;
        int count = 0;
        for (int i = 1; i< row +1;i++) {
            for (int j = 1; j< col +1;j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j - 1] + 1;
                 if ((dp[i-1][j - 1] + 1) > maxlen) {
                     maxlen = dp[i-1][j - 1] + 1;
                 }
        
            } else {
                dp[i][j] = 0;
            }
            }
        }
            return maxlen;
    }
