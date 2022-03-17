/* 

954. Array of Doubled Pairs

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

Example 1:

Input: arr = [3,1,3,6]
Output: false

Example 2:

Input: arr = [2,1,2,6]
Output: false

Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, int> m;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            int num = arr[i];
            if (m.count(num*2) > 0) {
                m[num*2]--;
                if (m[num*2] == 0) {
                    m.erase(num*2);
                }
            } else if ((num % 2 == 0) && (m.count(num / 2) > 0)) {
                m[num/2]--;
                if (m[num/2] == 0) {
                    m.erase(num/2);
                }
            } else {
                m[num]++;
            }
        }
        return m.size() == 0;
    }
};