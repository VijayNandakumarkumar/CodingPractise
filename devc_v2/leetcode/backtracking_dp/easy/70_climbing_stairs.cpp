/*

70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

*/

//Solution: 1 (similar to fibonacci series)

int climbStairs(int n) {
        vector<int> v (n+1, 0);
        v[0]= 1;
        v[1]= 1;
        vector<int>::iterator it;
        for(int i = 2;i<=n;i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }


//Solution: 2 (sub-optimal solution - using recursion)

int climbStairs(int n) {
        vector<int> nway;
        nway.push_back(0);
        for(int i = 1;i<=2;i++) {
            findTotalWays(n - i, nway);
        }
        return nway[0];
    }
    void findTotalWays(int n, vector<int> &nway) {
        if (n == 0) {
            nway[0]++;
            return;
        }
        for(int i = 1;i<=2;i++) {
            if (i <= n)
                findTotalWays(n - i, nway);
        }
    }



 

