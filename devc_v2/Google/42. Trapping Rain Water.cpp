/*

// Note - 7

42. Trapping Rain Water
Hard

23037

314

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


*/

class Solution {
public:
    /* Own solution
    int trap(vector<int>& height) {
        stack<int> vols;
        int vol=0;
        int l=0, n=height.size(), cur = 0;
        for (int i=0; i<n; i++) {
            cur = height[i];
            if (l==0 && cur) {
                l=height[i];
                continue;
            } else {
                if (cur < l) {
                    vols.push(l-cur);
                } else if (cur >= l) {
                    if (vols.size() > 0) {
                        while(!vols.empty()) {
                            vol += vols.top();
                            vols.pop();
                        }
                    }
                    l = cur;
                }
            }
        }
        int rmax = 0;
        while(!vols.empty()) {
            cur = vols.top();
            vols.pop();
            if ((l-cur) < rmax) {
                vol += rmax-(l-cur);
            } else {
                rmax = l-cur;
            }
        }
        return vol;
    }*/
/*  From Solution tab  
int trap(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
*/
    // From tech dose
    int trap(vector<int>& height)
    {
        int trapperWater=0;
        int n = height.size();
        if (n<=2) {
            return 0;
        }
        int leftMax = height[0], rightMax = height[n-1];
        int left = 1, right=n-2;
        while(left<=right) {
            if (leftMax < rightMax) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    trapperWater += leftMax-height[left];
                }
                left++;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    trapperWater += rightMax-height[right];
                }
                right--;
            }
        }
        return trapperWater;
    }
};