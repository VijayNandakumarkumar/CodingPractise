/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]

*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i =0;i<nums.size();i++) {
            if (nums[i] == 0) {
                num0++;
            } else if (nums[i] == 1) {
                num1++;
            } else {
                num2++;
            }
        }
        int i = 0;
        while(num0 > 0) {
            nums[i++] = 0;
            num0--;
        }
        while(num1 > 0) {
            nums[i++] = 1;
            num1--;
        }
        while(num2 > 0) {
            nums[i++] = 2;
            num2--;
        }
    }
};


