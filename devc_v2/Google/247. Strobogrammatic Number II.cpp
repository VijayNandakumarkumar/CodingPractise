/* 

247. Strobogrammatic Number II

Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: n = 2
Output: ["11","69","88","96"]

Example 2:

Input: n = 1
Output: ["0","1","8"]

*/

class Solution {
public:
    /* Our solution plain recursive permutation.
    vector<string> findStrobogrammatic(int n) {
        if (n==0) {
            return {};
        }
        vector<char> nums {'1', '8', '6', '9', '0'};
        
        vector<string> res;
        getAllStrobogrammaticNumbers(nums, n, res, "");
        return res;
    }
    
    void getAllStrobogrammaticNumbers(vector<char> &nums, int n, vector<string> &res, string cur) {
        if (n == cur.length()) {
            if (isStrobogrammatic(cur))
                res.push_back(cur);
            return;
        }
        cout<<cur<<" - cur \n";
        for (int i=0; i<nums.size(); i++) {
            cur.push_back(nums[i]);
            getAllStrobogrammaticNumbers(nums, n, res, cur);
            cur.pop_back();
        }
        return;
    }
    
    bool isStrobogrammatic(string num) {
        if (num.size() > 1 && num[0] == '0') {
            return false;
        }
        int n = num.length();
        for(int i=0; i<n; i++) {
            switch(num[i]) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '7':
                    return false;
                case '6':
                    if (num[n-i-1] != '9') {
                        return false;
                    }
                    break;
                case '9':
                    if (num[n-i-1] != '6') {
                        return false;
                    }
                    break;
                case '8':
                case '0':
                case '1':
                    if (num[n-i-1] != num[i]) {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
    */
    
    /* Sub Optimal - recursive solution
    vector<string> findStrobogrammatic(int n) {
        if (n==0) {
            return { "" };
        }
        vector<vector<char>> nums {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'0', '0'}, {'9', '6'}};
        
        return getAllStrobogrammaticNumbers(nums, n, n);
    }
    vector<string> getAllStrobogrammaticNumbers(vector<vector<char>> &nums, int n, int curLen) {
        // cout<<"Camme rejre";
        if (curLen == 0) {
            return { "" };
        } 
        if (curLen == 1) {
            return {"0", "1", "8"};
        }
        
        vector<string> prevStrobNums = getAllStrobogrammaticNumbers(nums, n, curLen-2);
        vector<string> curStrobNums;
        cout<<prevStrobNums.size();
        for (int i=0; i<prevStrobNums.size(); i++) {
            for (int j=0; j<nums.size(); j++) {
                if (nums[j][0] != '0' || curLen != n) {
                    curStrobNums.push_back(nums[j][0] + prevStrobNums[i] + nums[j][1]);
                }
            }
        }
        return curStrobNums;
    } */
    
    // Optimal solution - using queue, but same logic as prev recursive solution.
    vector<string> findStrobogrammatic(int n) {
        if (n==0) {
            return { "" };
        }
        vector<vector<char>> nums {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'0', '0'}, {'9', '6'}};
        
        queue<string> strobNums;
        
        int curLen = 0;
        if (n%2 == 0) {
            strobNums.push("");
        } else {
            strobNums.push("0");
            strobNums.push("1");
            strobNums.push("8");
            curLen = 1;
        }
        
        while(curLen < n) {
            curLen += 2;
            for (int i=strobNums.size(); i>0; i--) {
                string curNum = strobNums.front();
                strobNums.pop();
                for (int j=0; j<nums.size(); j++) {
                    if (nums[j][0] != '0' || curLen != n) {
                        strobNums.push(nums[j][0] + curNum + nums[j][1]);
                    }
                }
            }
        }
        vector<string> res;
        while(!strobNums.empty()) {
            res.push_back(strobNums.front());
            strobNums.pop();
        }
        return res;
    }
};