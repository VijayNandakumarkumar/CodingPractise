/*

15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int x = 0, y = 0,z = 0, new_sum = 0;
        sort(nums.begin(), nums.end());
        int i = 0,j=0, check_sum = 0;
        vector<vector<int> > v;
        set<vector<int> > set_of_vectors; 
        for (int s = 0;s<nums.size();s++) {
            new_sum = -1 * nums[s];
            i = s + 1;
            j = nums.size() - 1;
            while (i<j) {
                check_sum = nums[i] + nums[j];
                if (check_sum < new_sum) {
                    i++;
                } else if (check_sum > new_sum) {
                    j--;
                } else if (check_sum == new_sum) {
                    vector<int> vs {nums[s], nums[i], nums[j]};
                    if (set_of_vectors.find(vs) == set_of_vectors.end()) {
                        set_of_vectors.insert(vs);
                        v.push_back(vs);
                    }
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};

