/*

222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1

*/

Solution 1: Optimal (bin of bin search)

int depth(TN root) {
        int d = 0;
        if (root == NULL) {
            return d;
        } 
        while (root->left != NULL) {
            ++d;
            root = root->left;
        }
        return d;
    }
    bool exists(int idx, TN root, int d) {
        int left = 0, right = pow(2, d) - 1;
        
        for(int i = 0;i<d;i++) {
            int pivot = (left + right) / 2;
            if (idx <= pivot) {
                root = root->left;
                right = pivot;
            } else {
                root = root->right;
                left = pivot + 1;
            }
        }
        return root != NULL;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int d = depth(root);
        int left = 1, right = pow(2, d) - 1;
        while (left <= right) {
            int pivot = (left + right) / 2;
            if(exists(pivot, root, d)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        
        return pow(2, d) - 1 + left;
        
    }

// Solution 2: SubOptimal (mod bst - only till height - 1)

typedef struct TreeNode* TN;
    int depth(TN root) {
        int d = 0;
        if (root == NULL) {
            return d;
        } 
        while (root->left != NULL) {
            ++d;
            root = root->left;
        }
        return d;
    }
    int countNodes(TreeNode* root) {
        int n = 0;
        if (root == NULL) {
            return n;
        }
        int d= depth(root);
        queue<TN> q;
        q.push(root);
        n++;
        int popN = 0;
        int popNL = pow(2, d) - 1;
        while(!q.empty() && popN <= popNL){
            TN t= q.front();
            q.pop();
            popN++;
            if (t->left!=NULL) {
                q.push(t->left);
                n++;
                if (t->right!=NULL){
                    q.push(t->right);
                    n++;
                }
            }
        }
        return popNL + q.size()+1;
    }

// Solution 3: BST.

typedef struct TreeNode* TN;
    int depth(TN root) {
        int d = 0;
        if (root == NULL) {
            return d;
        } 
        while (root->left != NULL) {
            ++d;
            root = root->left;
        }
        return d;
    }
    int countNodes(TreeNode* root) {
        int n = 0;
        if (root == NULL) {
            return n;
        }
        
        queue<TN> q;
        q.push(root);
        n++;
        
        while(!q.empty()){
            TN t= q.front();
            q.pop();
            if (t->left!=NULL) {
                q.push(t->left);
                n++;
                if (t->right!=NULL){
                    q.push(t->right);
                    n++;
                }
            }
        }
       return n;
    } 
