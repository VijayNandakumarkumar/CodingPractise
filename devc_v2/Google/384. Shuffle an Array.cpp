/*

384. Shuffle an Array

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

    Solution(int[] nums) Initializes the object with the integer array nums.
    int[] reset() Resets the array to its original configuration and returns it.
    int[] shuffle() Returns a random shuffling of the array.

 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

*/

class Solution {
public:
    vector<int> org;
    vector<int> shuf;
    Solution(vector<int>& nums) {
        org.assign(nums.begin(), nums.end());
        shuf.assign(nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return org;
    }
    
    // vector<int> shuffle() {
    //     next_permutation(shuf.begin(), shuf.end());
    //     return shuf;
    // }
    
    vector<int> shuffle() {
        int n = shuf.size();
        for (int i=0; i<n-1; i++) {
            int rn = random(i, n-1);
            int temp = shuf[i];
            shuf[i] = shuf[rn];
            shuf[rn] = temp;
        }
        return shuf;
    }
    
    int random(int min, int max) //range : [min, max]
    {
       static bool first = true;
       if (first) 
       {  
          srand( time(NULL) ); //seeding for the first time only!
          first = false;
       }
       return min + rand() % (( max + 1 ) - min);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */