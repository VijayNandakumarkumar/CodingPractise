/*

137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

*/

// Solution - 1 Optimal - non intuitive (Bitwise manipulation)
// O(n) - time
// O(1) -n space

int singleNumber(vector<int>& nums) {
        
        int ones = 0;
        int twos = 0;
        for(auto ele : nums) {
            ones = (ones ^ ele) & (~twos);
            twos = (twos ^ ele) & (~ones);
        }
        return ones;
    }

//Solution - 2: Sub optimal (O(n) and O(n) 

int singleNumber(vector<int>& nums) {
        list<int> freq_list;
        unordered_set<int> s;
        unordered_map<int, list<int>::iterator> itr;
        
        for (int i = 0;i<nums.size() ;i++) {
            if (s.find(nums[i]) != s.end()) {
                if (itr.find(nums[i]) != itr.end()) {
                    freq_list.erase(itr[nums[i]]);
                    itr.erase(nums[i]);
                }
            } else {
                s.insert(nums[i]);
                freq_list.push_back(nums[i]);
                itr[nums[i]] = --freq_list.end();
            }
        }
        return freq_list.front();
  }
