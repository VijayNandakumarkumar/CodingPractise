/*

951. Flip Equivalent Binary Trees

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 

Example 1:
Flipped Trees Diagram

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.

Example 2:

Input: root1 = [], root2 = []
Output: true

Example 3:

Input: root1 = [], root2 = [1]
Output: false


*/

// Our own solution.

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL) {
            return root1 == root2;
        }
        
        if (root1->val != root2->val) {
            return false;
        }
        
        bool isLeft = flipEquiv(root1->left, root2->left) || flipEquiv(root1->left, root2->right);
        bool isRight = flipEquiv(root1->right, root2->right) || flipEquiv(root1->right, root2->left);
        if (isLeft && isRight) {
            return true;
        }
        return false;
    }

    // Fromm Solution tab - just for BST vectors for both trees and compare.

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        vector<int> t;
        vector<int> l;
        
        dfs(root1, t);
        dfs(root2, l);
        if (t.size() != l.size())
            return false;
        for (int i=0; i<t.size(); i++) {
            if (t[i]!=l[i])
                return false;
        }
        return true;
    }
    
    void dfs(TreeNode* node, vector<int> &vals) {
        if (node != NULL) {
            vals.push_back(node->val);
            int L = node->left != NULL ? node->left->val : -1;
            int R = node->right != NULL ? node->right->val : -1;

            if (L < R) {
                dfs(node->left, vals);
                dfs(node->right, vals);
            } else {
                dfs(node->right, vals);
                dfs(node->left, vals);
            }

            vals.push_back(NULL);
        }
    }
};