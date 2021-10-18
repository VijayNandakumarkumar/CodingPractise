/*

1022. Sum of Root To Leaf Binary Numbers


You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
Example 3:

Input: root = [1]
Output: 1
Example 4:

Input: root = [1,1]
Output: 3

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
    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        vector<int> v;
        vector<int> temp;
        v.push_back(0);
        findSum(root, v, temp);
        return v[0];
    }
    
    void findSum(TreeNode* root, vector<int> &v, vector<int> &temp) {
        if (root == NULL) {
            return;
        }
        if ((root->left == NULL) && (root->right == NULL)) {
            temp.push_back(root->val);
            if (temp.size() > 0) {
                int sum = 0;
                for(int i = 0; i<temp.size();i++) {
                    sum += temp[i] * pow(2, temp.size() - (i + 1));
                }
                v[0] += sum;
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        findSum(root->left, v, temp);
        findSum(root->right, v, temp);
        if (temp.size() > 0)
            temp.pop_back();
    }
};