/*

98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true

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
    
    bool isValidBST(TreeNode* root) {
        return checkIsValidBst(root, LONG_MAX, LONG_MIN);
    }
    
    bool checkIsValidBst(TreeNode* root, long max, long min) {
        if (root == NULL) {
            return true;
        }
        // cout<<root->val<<" "<<max<<""
        if (((min != LONG_MIN) && (root->val <= min)) || ((max != LONG_MAX) && (root->val >= max))) {
            return false;
        }
        
        return checkIsValidBst(root->left, root->val, min) && checkIsValidBst(root->right, max, root->val);
    }
};
