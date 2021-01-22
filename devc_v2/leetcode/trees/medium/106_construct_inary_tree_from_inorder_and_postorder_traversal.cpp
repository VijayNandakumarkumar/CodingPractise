/*

106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

*/

class Solution {
public:
    typedef struct TreeNode* Node;
    int preInd = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(postorder, inorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
    
    Node createTree(vector<int> &postorder, vector<int> &inorder, int start, int end, int index) {
        if(start > end) {
            return NULL;
        }
        Node root = new TreeNode(postorder[index]);
        int pos = 0;
        for(int i =start;i<=end;i++){
            if(inorder[i] == root->val) {
                pos = i;
            }
        }
        root->left = createTree(postorder, inorder, start, pos - 1, index - (end - pos) -1);
        root->right = createTree(postorder, inorder, pos + 1, end, index -1);
        return root;
    }
};
