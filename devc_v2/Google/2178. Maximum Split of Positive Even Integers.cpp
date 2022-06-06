/*

2178. Maximum Split of Positive Even Integers

You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

    For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.

Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

 

Example 1:

Input: finalSum = 12
Output: [2,4,6]
Explanation: The following are valid splits: (12), (2 + 10), (2 + 4 + 6), and (4 + 8).
(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
Note that [2,6,4], [6,2,4], etc. are also accepted.

Example 2:

Input: finalSum = 7
Output: []
Explanation: There are no valid splits for the given finalSum.
Thus, we return an empty array.

Example 3:

Input: finalSum = 28
Output: [6,8,2,12]
Explanation: The following are valid splits: (2 + 26), (6 + 8 + 2 + 12), and (4 + 24). 
(6 + 8 + 2 + 12) has the maximum number of integers, which is 4. Thus, we return [6,8,2,12].
Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.

*/

// Our recursive solution, but without recursion iteration below is better one!

class Solution {
public:
//     vector<long long> maximumEvenSplit(long long finalSum) {
//         int max = 0;
//         vector<long long>  result;
//         vector<long long>  maxResult;
//         set<long long> s;
//         getMaxSplit(finalSum, result, max, s, maxResult, 2);
//         return maxResult;
//     }
    
//     void getMaxSplit(long long finalSum, vector<long long>  &result, int &max, set<long long> &s, vector<long long>  &maxResult, int ind) {
//         if (finalSum == 0) {
//             if (max < result.size()) {
//                 cout<<"came here, max "<<max;
//                 printResult(result);
//                 max = result.size();
//                 maxResult.clear();
//                 maxResult.insert(maxResult.begin(), result.begin(), result.end());
//             }
//         } 
//         // else if (finalSum < 0) 
//         for (int i=ind; i<=finalSum; i=i+2) {
//             if ((i%2 == 0) && (s.find(i) == s.end()) && finalSum-i >= 0){
//                 cout<<"inserting = "<<i<<" final sum"<<finalSum<<" \n";
//                 result.push_back(i);
//                 s.insert(i);
//                 getMaxSplit(finalSum-i, result, max, s, maxResult, i);
//                 cout<<"Before pop";
//                 printResult(result);
//                 s.erase(result.back());
//                 result.pop_back();
//                 cout<<"After pop";
//                 printResult(result);
//             }
//         }
//         return;
//     }
    
//     void printResult(vector<long long>  &result) {
    //     for(auto& l: result) {
    //         cout<<l<<" ";
    //     }
    //     cout<<"\n";
    // }

    ------------------------------------------------------------------------

vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> ans;
    if (finalSum%2 != 0) {
        return ans;
    } 
    
    for(int i=2; finalSum-i>i; i=i+2) {
        ans.push_back(i);
        finalSum-=i;
    }
    ans.push_back(finalSum);
    return ans;
}
    
};