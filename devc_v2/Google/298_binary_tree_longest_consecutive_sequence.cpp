/*

298. Binary Tree Longest Consecutive Sequence

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.Example 1:

*/

// Solution: 1 (O(n))

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
    int longestConsecutive(TreeNode* root) {
        int seq = 0;
        getLongestConsecutive(root, seq, 0, 0);
        return seq;
    }
    void getLongestConsecutive(TreeNode* root, int &seq, int target, int count) {
        if (root == NULL) {
            return;
        }
        if (root->val == target) {
            count++;
        } else {
            count = 1;
        }
        seq = max(seq, count);
        getLongestConsecutive(root->left, seq, root->val + 1, count);
        getLongestConsecutive(root->right, seq, root->val + 1, count);
    }
};
