/*

202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false

*/

//Optimal solution from leetcode solutions. Detecting cycle in a linked list.

class Solution {

     public int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    public boolean isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
}


// Own solution - works
// time O(logn) (it takes log n time to find the length of a number, and that is the max time consuming operation.)
class Solution {
public:
    bool isHappy(int n) {
       if (n == 1) {
           return true;
       }
        int sum = 0;
        set<int> s;
    while((n != 1)) {
        s.insert(n);
        sum=0;
        while(n!=0) {
            sum += pow((n%10),2);
            n = n/10;
        }
        if(sum==1) {
            return true;
        }
        if (s.find(sum) != s.end()){
            return false;
        }
        n=sum;
    }
        return false;
    }
};