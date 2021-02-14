/*

1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

*/

// Both solutions are of the same time and space - O(n)

// Solution - 1: Top-down (Own sol)

typedef struct TreeNode* TNode;
    vector<TNode> v;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL || to_delete.size() == 0) {
            return {root};
        }
        auto it = find(to_delete.begin(), to_delete.end(), root->val);
        if (it == to_delete.end()) {
            v.push_back(root);
        }
        deleteNode(root, to_delete);
        return v;
    }
    
    TNode deleteNode(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL || to_delete.size() == 0) {
            return root;
        }
        auto it = find(to_delete.begin(), to_delete.end(), root->val);
        if (it != to_delete.end()) {
            to_delete.erase(it);
            if (root->left != NULL) {
                if(deleteNode(root->left,to_delete) != NULL) {
                    v.push_back(root->left);
                }
            }
            if (root->right != NULL) {
                if(deleteNode(root->right,to_delete) != NULL) {
                    v.push_back(root->right);
                }
            }
            return NULL;
        }
        
        root->left = deleteNode(root->left,to_delete);
        root->right = deleteNode(root->right,to_delete);
        return root;
    }

// Solution - 2: Bottom-up

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL || to_delete.size() == 0) {
            return {root};
        }
        
        
        vector<TNode> v;
        deleteNode(root, to_delete, v);
        auto it = find(to_delete.begin(), to_delete.end(), root->val);
        if (it == to_delete.end()) {
            v.push_back(root);
        }
        return v;
    }
    
    TNode deleteNode(TreeNode* root, vector<int>& to_delete, vector<TNode> &v) {
        if (root == NULL) {
            return root;
        }
        root->left = deleteNode(root->left,to_delete, v);
        root->right = deleteNode(root->right,to_delete, v);
        
        auto it = find(to_delete.begin(), to_delete.end(), root->val);
        if (it != to_delete.end()) {
            if (root->left != NULL) {
                v.push_back(root->left);
            }
    
            if (root->right != NULL) {
                v.push_back(root->right);
            }
            
            return NULL;
        }
        return root;
    }


