/*

230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1


   3
  / \
 1   4
  \
   2
Output: 1


*/


class Solution {
public:
    int kth = 0;
    int val = 0;
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root, k);
        return val;
    }
    void inorder(TreeNode* root, int k) {
        if (root == NULL) 
        {
            return;
        }
            inorder(root->left, k);
            if (k==++kth) {
                val = root->val;
                return;
            }     
            inorder(root->right, k);
    }
};
