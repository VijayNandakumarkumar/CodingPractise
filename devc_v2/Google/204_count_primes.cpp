/*

204. Count Primes

Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/


class Solution {
public:
    int countPrimes(int n) {
       if (n == 0 || n == 1)  {
           return 0;
       }
        vector<bool> v (n);
        for(int i = 2; i * i <= n; i++) {
            if (!v[i]) {
                for (int j = i; j*i <= n; j++) {
                    v[j*i] = true;
                }
            }
        }
        
        int count = 0;
        
        for(int i = 2; i < n; i++) {
            if (!v[i])
                count++;
        }
        
        return count;
        
    }
};
