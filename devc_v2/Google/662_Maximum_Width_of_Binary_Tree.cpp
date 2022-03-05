/*

662. Maximum Width of Binary Tree
Medium

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        vector<int> levelWidth;
        while(!q.empty()) {
            pair<TreeNode*, unsigned long long> headNode = q.front();
            int n = q.size();
            pair<TreeNode*, unsigned long long> curPair;
            for (int i=0; i<n; i++) {
                curPair = q.front();
                q.pop();
                TreeNode* node = curPair.first;
                unsigned long long ind = curPair.second;
                if(node->left != NULL) {
                    q.push({node->left, ind*2});
                }
                if(node->right != NULL) {
                    q.push({node->right, ind*2 + 1});
                }
            }
            int curWidth = (curPair.second - headNode.second) + 1;
            maxWidth = (curWidth > maxWidth) ? curWidth : maxWidth;
        }
        
        
        return maxWidth; 
    }
    /*
    int getPosition(TreeNode* root, int pos, bool isLeft) {
        if (root == NULL) {
            return pos;
        }
        if (root->left == NULL && root->right == NULL) {
            return pos;
        }
        if (isLeft) {
            if (root->left != NULL) {
                return getPosition(root->left, (pos*2)+1, isLeft);
            } else {
                return getPosition(root->right, (pos*2)+2, isLeft);
            }
        } else {
            if (root->right != NULL) {
                return getPosition(root->right, (pos*2)+2, isLeft);
            } else {
                return getPosition(root->left, (pos*2)+1, isLeft);
            }
        }
    }
    */
};