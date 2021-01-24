/*

46. Permutations.

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

*/


// Solution 1: My Solution.

vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            return {nums};
        }
        vector<vector<int> > r;
        vector<int> v;
        getAllPermutation(nums, v, r, nums.size());
        return r;
    }
    
    void getAllPermutation(vector<int>& nums, vector<int>& current, vector<vector<int> > &r, int max) {
        if (current.size() == max) {
            r.push_back(current);
            return;
        }
        for (int i = 0;i<nums.size(); i++) {
            int number = nums[i];
            current.push_back(number);
            nums.erase(nums.begin() + i);
            getAllPermutation(nums, current, r, max);
            nums.insert(nums.begin() + i, number);
            current.pop_back();
        }
        
    }

// Solution 2: knowledge centre

vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            return {nums};
        }
        vector<vector<int> > r;
        
        for (int i = 0;i<nums.size(); i++) {
            vector<int> v (nums.begin(), nums.end());
            int number = v[i];
            v.erase(v.begin() + i);
            auto res = permute(v);
            for (int i =0;i<res.size();i++) {
                vector<int> _v = res[i];
                _v.insert(_v.begin(), number);
                r.push_back(_v);
            }
        }
        return r;
    }


