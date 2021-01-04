/*

101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

*/

bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymTree(root->left, root->right);
    }
    
    bool isSymTree(TreeNode* leftRoot,TreeNode* rightRoot) {
        if(leftRoot == NULL && rightRoot==NULL) {
            return true;
        } else if (leftRoot == NULL) {
            return false;
        } else if (rightRoot == NULL) {
            return false;
        }
        if(leftRoot->val != rightRoot->val) {
            return false;
        }
        bool left = isSymTree(leftRoot->left, rightRoot->right);
        bool right = isSymTree(leftRoot->right, rightRoot->left);
        if (left && right) {
            return true;
        }
        return false;
    }
};
