/*

1822. Sign of the Product of an Array

There is a function signFunc(x) that returns:

    1 if x is positive.
    -1 if x is negative.
    0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

 

Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

Example 2:

Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0

Example 3:

Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

*/

class Solution {
public:

	// Our solution (same time complexity as the next solution)
    // int arraySign(vector<int>& nums) {
    //     int isNegative = false;
    //    for (auto& i : nums) {
    //        if (i<0) {
    //            isNegative = !isNegative;
    //        } else if (i==0) {
    //            return 0;
    //        }
    //    }
    //     return isNegative ? -1 : 1;
    // }
    
    // From hints
    int arraySign(vector<int>& nums) {
        int prod = 1;
       for (auto& i : nums) {
           if (i<0) {
               prod *= -1;
           } else if (i==0) {
               return 0;
           }
       }
        return prod;
    }
};