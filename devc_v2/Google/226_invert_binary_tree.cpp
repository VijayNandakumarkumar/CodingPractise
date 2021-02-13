/*

226. Invert Binary Tree

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

// Solution Optimal
//time - O(n)
//space - O(h) -> O(n)

TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        TreeNode* leftTree = root->left;
        root->left = root->right;
        root->right = leftTree;
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }


