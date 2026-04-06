/*
3890. Integers With Multiple Sum of Two Cubes

You are given an integer n.

An integer x is considered good if there exist at least two distinct pairs (a, b) such that:

a and b are positive integers.
a <= b
x = a3 + b3
Return an array containing all good integers less than or equal to n, sorted in ascending order.

 

Example 1:

Input: n = 4104

Output: [1729,4104]

Explanation:

Among integers less than or equal to 4104, the good integers are:

1729: 13 + 123 = 1729 and 93 + 103 = 1729.
4104: 23 + 163 = 4104 and 93 + 153 = 4104.
Thus, the answer is [1729, 4104].

Example 2:

Input: n = 578

Output: []

Explanation:

There are no good integers less than or equal to 578, so the answer is an empty array.

 

Constraints:

1 <= n <= 109

*/


class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> sumFreq;
        vector<int> ans;

        int limit = cbrt(n);
        for (int i=1; i<=limit; i++) {
            int i3 = pow(i, 3);
            for (int j=i; j<=limit; j++) {
                int j3 = pow(j, 3);
                int sum = i3 + j3;
                
                if (sum > n) break;
                
                sumFreq[sum]++;
            }
        }

        for(auto &a: sumFreq) {
            if (a.second >= 2) {
                cout<<a.first<<" "<<a.second<<endl;
                ans.push_back(a.first);
            }
        }

        if (ans.size() > 0) 
            sort(ans.begin(), ans.end());
        
                return ans;
    }
};
