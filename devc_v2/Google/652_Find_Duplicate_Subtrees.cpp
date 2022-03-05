/*

652. Find Duplicate Subtrees

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

Input: root = [2,1,1]
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
    map<string, int> m;
    vector<TreeNode*> v;
    set<string> s;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root==NULL) {
            return {};
        }
        findDuplicates(root);
        return v;
    }
    
    string findDuplicates(TreeNode* root) {
        if (root==NULL) {
            return "X";
        }
        string left = findDuplicates(root->left)+"l";
        string right = findDuplicates(root->right)+"r";
        string temp = to_string(root->val) + "root" + left + right;
        m[temp]++;
        if (m[temp] > 1) {
            if (s.find(temp) == s.end()) {
                cout<<temp<<"\n";
                s.insert(temp);
                v.push_back(root);
            }
        }
        return temp;
    }
};