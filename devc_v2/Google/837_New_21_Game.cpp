/*

837. New 21 Game

Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets k or more points.

Return the probability that Alice has n or fewer points.

Answers within 10-5 of the actual answer are considered accepted.

 

Example 1:

Input: n = 10, k = 1, maxPts = 10
Output: 1.00000
Explanation: Alice gets a single card, then stops.


*/

class Solution {
public:
    
    //youtube: https://www.youtube.com/watch?v=2wCShtvcP0Q
    double new21Game(int n, int k, int maxPts) {
        if (k==0 || n >= k + maxPts) {
            return 1.0;
        }
        vector<double> dp (n+1, 0.0);
        dp[0] = 1.0; // probability of have 0 or less points is 100%, since at initially we will have 0;
        
        // Our goal is to return probability of n or less points
        // Which is basically probility of getting up anything in between
        // k to n. This is because we will stop only when we reach k and so
        // the lower end is k and high end is n.
        
        // dp[14] = dp[13]*P(13) + dp[12]*P(12) + ... + dp[14 - maxPts]*P(14-maxPts)
        // P(1) = 1/maxPts = P(2) => Given iin question.
        // So, dp[14] = dp[13]*1/maxPts + dp[12]*1/maxPts + ... + dp[14 - maxPts]*1/maxPts
        // dp[14] = 1/maxPts (dp[13] + dp[13] + ... + dp[8]) //if maxPts is 6 
        // dp[15] = 1/maxPts (dp[14] + dp[13] + ... + dp[9]) // so the dp sum is sliding...
        double runningSum = 1.0; //dp[0]
        double res = 0.0;
        for(int i=1; i<=n; i++) {
            // assuming dp sum is already prepared.
            dp[i] = runningSum / (double) maxPts;
            //front end of runningSum
            if (i<k) {
                runningSum += dp[i];
            } else {
                res += dp[i];
            }
            
            if(i-maxPts >= 0) {
                runningSum -= dp[i-maxPts];
            }
        }
        return res;
    }
    
    
    /*
    // TLE Solution
    double new21Game(int n, int k, int maxPts) {
        if (k==0 || n >= k + maxPts) {
            return 1.0;
        }
        
        vector<double> dp (n+1, 0.0);
        dp[0] = 1.0; 
        
        double res = 0.0;
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=maxPts; j++) {
                if ((i-j >=0 ) && (i-j < k)) {
                    dp[i] += dp[i-j]/(double)maxPts;
                }
            }
        }
        
        for (int i=k;i<=n;i++) {
            res += dp[i];
        }
        return res;
    }
    */
};