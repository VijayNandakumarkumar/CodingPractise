/*

528. Random Pick with Weight
//Knowledge centre

You are given an array of positive integers w where w[i] describes the weight of ith index (0-indexed).

We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1]. pickIndex() should return the integer proportional to its weight in the w array. For example, for w = [1, 3], the probability of picking the index 0 is 1 / (1 + 3) = 0.25 (i.e 25%) while the probability of picking the index 1 is 3 / (1 + 3) = 0.75 (i.e 75%).

More formally, the probability of picking index i is w[i] / sum(w).

 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. Since there is only one single element on the array the only option is to return the first element.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It's returning the second element (index = 1) that has probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It's returning the first element (index = 0) that has probability of 1/4.

Since this is a randomization problem, multiple answers are allowed so the following outputs can be considered correct :
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.

*/

class Solution {
public:

    // Tech Dose - June 10, 2022
    vector<int> v;
    Solution(vector<int>& w) {
        for (auto i:w) {
            v.push_back((v.empty() ? 0 : v.back()) + i);
        }
    }
    
    int pickIndex() {
        int randNum = rand() % v.back();
        return upper_bound(v.begin(), v.end(), randNum) - v.begin();
    }


    // Knowledge center
    vector<int> weight;
    int len = 0;
    int prefix_sum = 0;
    int totalSum = 0;
    vector<int> a;
    Solution(vector<int>& w) { 
        weight = w;
        len = w.size();
        for (int i = 0;i<len;i++) {
            prefix_sum += w[i];
            a.push_back(prefix_sum);
        }
        totalSum = prefix_sum;
    }
    
    int pickIndex() {
       
        int r = (rand() % totalSum) + 1;
        int low = 0, high = len;
        while (low < high) {
            int mid = (low + high) /2;
            if (r > a[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
