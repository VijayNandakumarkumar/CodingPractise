/*

922. Sort Array By Parity II

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Example 2:

Input: nums = [2,3]
Output: [2,3]

*/

class Solution {
public:
    
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i=1, k=0;
        while(i<n && k<n) {
            if (nums[k]%2==0) {
                k+=2;
                continue;
            } else if (nums[i]%2==0) {
                swap(nums[i], nums[k]);
                k+=2;
            }
            i+=2;
        }
        return nums;
    }
};