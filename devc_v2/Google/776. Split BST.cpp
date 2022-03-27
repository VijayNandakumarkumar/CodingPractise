/*

776. Split BST

Given the root of a binary search tree (BST) and an integer target, split the tree into two subtrees where one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value. It Is not necessarily the case that the tree contains a node with the value target.

Additionally, most of the structure of the original tree should remain. Formally, for any child c with parent p in the original tree, if they are both in the same subtree after the split, then node c should still have the parent p.

Return an array of the two roots of the two subtrees.

 

Example 1:

Input: root = [4,2,6,1,3,5,7], target = 2
Output: [[2,1],[4,3,6,null,null,5,7]]

Example 2:

Input: root = [1], target = 1
Output: [[1],[]]

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

// From Solution.
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (root == NULL) {
            return {NULL, NULL};
        } else if (root->val <= target) {
            vector<TreeNode*> roots = splitBST(root->right, target);
            root->right = roots[0];
            roots[0] = root;
            return roots;
        } else {
            vector<TreeNode*> roots = splitBST(root->left, target);
            root->left = roots[1];
            roots[1] = root;
            return roots;
        }
    }
};