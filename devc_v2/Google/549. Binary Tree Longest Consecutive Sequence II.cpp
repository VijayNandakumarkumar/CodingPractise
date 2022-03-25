/*

549. Binary Tree Longest Consecutive Sequence II

Given the root of a binary tree, return the length of the longest consecutive path in the tree.

A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.

    For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.

On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

 

Example 1:

Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].

Example 2:

Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxVal = 1;
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> curPair = getMaxSeq(root);
        return maxVal;
    }
    
    vector<int> getMaxSeq(TreeNode* root) {
        if (root==NULL) {
            return {};
        }
        
        vector<int> leftPair = getMaxSeq(root->left);
        vector<int> rightPair = getMaxSeq(root->right);
        if (leftPair.size()==0 && rightPair.size()==0) {
            return {1, 1};
        }
        vector<int> curPair (2, 1);
        if (leftPair.size() != 0) {
            int leftDiff = root->val - root->left->val;
            if (leftDiff == -1) {
                curPair[0] = max(curPair[0], leftPair[0] + 1);
            } else if (leftDiff == 1) {
                curPair[1] = max(curPair[1], leftPair[1] + 1);
            }
        }
        if (rightPair.size() != 0) {
            int rightDiff = root->val - root->right->val;
            if (rightDiff == -1) {
                curPair[0] = max(curPair[0], rightPair[0] + 1);
            } else if (rightDiff == 1) {
                curPair[1] = max(curPair[1], rightPair[1] + 1);
            }
        }
        maxVal = max(maxVal, curPair[0] + curPair[1] - 1);
        return curPair;
    }
};