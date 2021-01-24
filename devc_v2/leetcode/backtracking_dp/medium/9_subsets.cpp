/*

9. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/

Check CS dojo for better understanding.

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > r;
        vector<int> cur;
        getAllCombinations(nums, cur, r, 0);
        return r;
    }
    
    void getAllCombinations(vector<int>& nums, vector<int>& cur, vector<vector<int> > &r, int index) {
        // vector<int> v;
        // copy(cur.begin(), cur.end(), back_inserter(v));
        r.push_back(cur);
        
        for (int i = index;i< nums.size(); i++) {
            cur.push_back(nums[i]);
            getAllCombinations(nums, cur, r, i + 1);
            cur.pop_back();
        }
        
    }
