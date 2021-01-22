/*

105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

*/

class Solution {
public:
    int preInd = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, inorder.size() - 1);
    }
    TreeNode* createTree(vector<int> &preorder, vector<int> &inorder,int start, int end){
        if(start > end){
        return NULL;
        }
        TreeNode* node=new TreeNode(preorder[preInd++]);
        int pos;
        for(int i=start;i<=end;i++){
            if(inorder[i]==node->val){
                pos=i;
                break;
            }
        }
        node->left =createTree(preorder, inorder,start,pos-1);
        node->right =createTree(preorder, inorder, pos+1,end);
        return node;
    }
};
