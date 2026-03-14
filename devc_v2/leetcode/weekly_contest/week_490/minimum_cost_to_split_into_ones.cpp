/*
3857. Minimum Cost to Split into Ones

You are given an integer n.

In one operation, you may split an integer x into two positive integers a and b such that a + b = x.

The cost of this operation is a * b.

Return an integer denoting the minimum total cost required to split the integer n into n ones.

 

Example 1:

Input: n = 3

Output: 3

Explanation:

One optimal set of operations is:

x	a	b	a + b	a * b	Cost
3	1	2	3	2	2
2	1	1	2	1	1
Thus, the minimum total cost is 2 + 1 = 3.

Example 2:

Input: n = 4

Output: 6

Explanation:

One optimal set of operations is:

x	a	b	a + b	a * b	Cost
4	2	2	4	4	4
2	1	1	2	1	1
2	1	1	2	1	1
Thus, the minimum total cost is 4 + 1 + 1 = 6.

 

Constraints:

1 <= n <= 500

*/
Splitting doesn't matter here:
Any number x, if it is partioned as a + b, where a + b = x
Always taking the value of a as 1 gives a * b as a smallest multiple
For Example 6 can be partioned as
1 + 5 (1 * 5 = 5)
2 + 4 (2 * 4 = 8)
3 + 3 (3 * 3 = 9)
So multiplying by 1 is always smaller
If you taking 1 digit as 1, then you are summing up till n - 1
So 1 + 2 + 3 + 4 + 5 = 15, which is n * (n - 1) / 2
6 * (5) / 2 = 3 * 5 = 15

// Math Solution.
class Solution {
    public int minCost(int n) {
        return n * (n - 1) / 2;
    }
}

// DP Solution.

class Solution {
public:
    vector<int> dp;
    int minCost(int n) {
        if (dp.size() == 0) {
            dp.assign(n+1, 0);
        }
        if (n==1){
            return 0;
        } else if (dp[n]!=0) {
            return dp[n];
        }
        
        int cost = 0;
        if (n%2==0) {
            cost = pow(n/2, 2) + minCost(n/2) + minCost(n/2);;
        } else {
            cost = n-1 + minCost(n-1);
        }
        dp[n] = cost;
        return cost;
    }
};
