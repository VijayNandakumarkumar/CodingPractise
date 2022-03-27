/*

919. Complete Binary Tree Inserter

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

    CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
    int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
    TreeNode get_root() Returns the root node of the tree.

 

Example 1:

Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]

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
class CBTInserter {
public:
    TreeNode* treeRoot = NULL;
    queue<TreeNode*> nextRoot;
    queue<TreeNode*> curPath;
    CBTInserter(TreeNode* root) {
        if (root!=NULL) {
            treeRoot = root;
            curPath.push(root);
            parseTree();
        }  
    }
    
    void parseTree() {
        while(!curPath.empty()) {
            TreeNode* root = curPath.front();
            curPath.pop();
            nextRoot.push(root);
            if (root->left!=NULL) {
                nextRoot.push(root->left);
                curPath.push(root->left);
            }
            if (root->right!=NULL) {
                nextRoot.push(root->right);
                curPath.push(root->right);
            }
            if (root->left!=NULL && root->right!=NULL) {
                nextRoot.pop();
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode();
        newNode->val = val;
        TreeNode* root = NULL;
        while(!nextRoot.empty()) {
            root = nextRoot.front();
            cout<<root->val;
            if (root->left != NULL && root->right!=NULL) {
                nextRoot.pop();
                continue;
            }
            break;
        }
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            root->right = newNode;
        }
        nextRoot.push(newNode);
        return root->val;
    }
    
    TreeNode* get_root() {
        return treeRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */