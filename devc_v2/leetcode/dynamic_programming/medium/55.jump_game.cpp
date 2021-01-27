/*

55.Jump Game.

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it 

*/

Solution 1: Optimal (iteration)

bool canJump(vector<int>& nums) {
       int n = nums.size();
        int rechable = 0;
        for(int i = 0; i < n;i++) {
            if (rechable < i) 
                return false;
            else if (rechable >= n)
                return true;
            rechable = max(rechable, i + nums[i]);
        }
        return true;
}

Solution 2: Sub-Optimal (recursion and backtracking)

bool canJump(vector<int>& nums) {
	return jd(nums[0], 0, nums.size() - 1, nums);
}

 bool jd(int steps, int index, int dest, vector<int> &nums) {
        if (steps + index >= dest) {
            return true;
        }
        if (steps == 0) {
            return false;
        }
        if (index+steps <= dest && jd(nums[index+steps], index+steps, dest, nums))
            return true;
        for (int i = steps;i>0;i--) {
            if (jd(nums[index+i], index+i, dest, nums))
                return true;
        }
        return false;
    }

Solution 3: memoise backtracking to get the dp solution.
