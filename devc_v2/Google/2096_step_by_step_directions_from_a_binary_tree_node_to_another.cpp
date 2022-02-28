/*

2096. Step-By-Step Directions From a Binary Tree Node to Another

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:

Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.



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
    string getDirections(TreeNode* root, int lval, int rval) {
        if (root == NULL) {
            return "";
        }
        
        TreeNode* lca = find_lca(root, lval, rval);
        cout<<lca->val;
        string ls = "";
        string rs = "";
        getStringSeq(lca, lval, ls, true);
        getStringSeq(lca, rval, rs, false);
        return ls+rs;
    }
    
    bool getStringSeq(TreeNode* root, int val, string &s, bool isLeft) {
        if(root==NULL) {
            return false;
        }
        if(root->val == val) 
            return true;
        s += isLeft? "U" : "L";
        if(getStringSeq(root->left, val, s, isLeft)) {
            return true;
        }
        s.pop_back();
        s += isLeft? "U" : "R";
        if(getStringSeq(root->right, val, s, isLeft)) {
            return true;
        }
        s.pop_back();
        return false;
    }
    
    TreeNode* find_lca(TreeNode* root, int lval, int rval) {
        if (root == NULL) {
            return root;
        }
        if ((lval == root->val) || (rval == root->val)) {
            return root;
        }
        TreeNode* left = find_lca(root->left, lval, rval);    
        TreeNode* right = find_lca(root->right, lval, rval);
        if(left!=NULL && right!=NULL) {
            return root;
        }
        return (right != NULL) ? right : left;
    }
};