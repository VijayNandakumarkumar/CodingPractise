/*

366. Find Leaves of Binary Tree

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

    Collect all the leaf nodes.
    Remove all the leaf nodes.
    Repeat until the tree is empty.

 

Example 1:

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.

Example 2:

Input: root = [1]
Output: [[1]]


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

    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == NULL) {
            return {{}};
        }
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, vector<vector<int>> &res) {
        if (root == NULL) {
            return -1;
        }
        int height = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if (res.size() == height) {
            res.push_back({});
        }
        res[height].push_back(root->val);
        return height;
    }


    //Our solution (Also there is another solution where we can just index the nodes based on their height from bottom and then push them into the respective array index/buckets of leaves.)
    /*
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == NULL) {
            return {{}};
        }
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        root = findLeaves(root, res);
        while(root!=NULL) {
            res.push_back(v);
            root = findLeaves(root, res);
        }
        return res;
    }
   
    TreeNode* findLeaves(TreeNode* node, 
                         vector<vector<int>> &res) {
        if (node == NULL) {
            return NULL;
        }
        if ((node->left == NULL) && (node->right == NULL)) {
            res[res.size() - 1].push_back(node->val);
            return NULL;
        } 
        if (node->left != NULL) {
            node->left = findLeaves(node->left, res);
        } 
        if (node->right != NULL) {
            node->right = findLeaves(node->right, res);
        }
        return node;
    }
    */
    
    /* Best Solution
    
     vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, vector<vector<int>>& res){
        if(root == nullptr){
            return 0;
        }
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if(level > (int)res.size()){
            res.push_back(vector<int>());
        }
        res[level - 1].push_back(root->val);
        return level;
    }
    
    
    */
    
};