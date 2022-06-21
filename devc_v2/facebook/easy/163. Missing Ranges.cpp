/*

163. Missing Ranges

You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: ["2","4->49","51->74","76->99"]
Explanation: The ranges are:
[2,2] --> "2"
[4,49] --> "4->49"
[51,74] --> "51->74"
[76,99] --> "76->99"
Example 2:

Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.

*/

class Solution {
public:
	// Our Solution
    // vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    //     vector<string> ans;
    //     int j=0, len = nums.size();
    //     if (len==0) {
    //         ans.push_back(formatRange(lower, upper));
    //         return ans;
    //     }
    //     for(int i=lower; i<=upper && j<nums.size(); i++) {
    //         cout<<"i "<<i<<"\n";
    //         if (nums[j]==i) {
    //             j++;
    //         } else {
    //             ans.push_back(formatRange(i, nums[j]-1));
    //             i = nums[j]-1;
    //         }
    //     }
    //     if (nums[len-1] != upper) {
    //         ans.push_back(formatRange(nums[len-1]+1, upper));
    //     }
    //     return ans;
    // }
    
    // Our Solution
//      vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
//         vector<string> ans;
//         int j=lower, len = nums.size();
//         if (len==0) {
//             ans.push_back(formatRange(lower, upper));
//             return ans;
//         }
         
//         for (int i=0; i<len; i++) {
//             if(nums[i] == j) {
//                 j++;
//                 continue;
//             } else {
//                 ans.push_back(formatRange(j, nums[i]-1));
//                 j=nums[i]+1;
//             }
//         }
//         if (nums[len-1] != upper) {
//             ans.push_back(formatRange(nums[len-1]+1, upper));
//         }
//         return ans;
//     }
    
    // Fromm solution
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int prev = lower - 1;
        for (size_t i = 0; i <= nums.size(); i++) {
            int curr = (i < nums.size()) ? nums[i] : upper + 1;
            if (prev + 1 <= curr - 1) {
                result.push_back(formatRange(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return result;
    }
    
    string formatRange(int low, int high) {
        if  (low==high) {
            return to_string(low);
        } else {
            return to_string(low) + "->" + to_string(high);
        }
    }
};