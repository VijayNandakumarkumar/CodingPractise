/*

34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/

Solution 1: Optimal

vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> targetRange {-1, -1};

        int leftIdx = extremeInsertionIndex(nums, target, true);

        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false)-1;

        return targetRange;
    }
    
    int extremeInsertionIndex(vector<int> &nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();
        
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || left && nums[mid] == target) {
                hi = mid;
            } else
            {
                lo = mid+1;
            }
        }
        return lo;
    }

Solution 2: Suboptimal

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v {-1, -1};
         if (nums.size() == 1) {
             if (nums[0] == target) {
                 v[0] = 0;
                 v[1] = 0;
             } 
             return v;
         } else if (nums.size() == 0) {
            return v;
        }
        binFindTargetRange(0, nums.size() - 1, nums, v, target);
        return v;
    }
    void binFindTargetRange(int start, int end, vector<int> &nums, vector<int> &v, int target) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        int rs = 0, es = nums.size() - 1;
        if (nums[mid] == target) {
            if (mid != 0) {
                if (nums[mid - 1] != target) {
                    rs = mid;
                    v[0] = rs;
                } else {
                    binFindTargetRange(start, mid - 1, nums, v, target);
                }
            } else {
                v[0] = 0;
            }
            if (mid != (nums.size() - 1)) {
                if (nums[mid + 1] != target) {
                    es = mid;
                    v[1] = es;
                } else {
                    binFindTargetRange(mid + 1, end, nums, v, target);
                }
            } else {
                v[1] = es;
            }
            return;
        } else if (nums[mid] > target) {
            binFindTargetRange(start, mid - 1, nums, v, target);
        } else {
            binFindTargetRange(mid + 1, end, nums, v, target);
        }
        return;
    }

