/*

116. Populating Next Right Pointers in Each Node

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

*/

class Solution {
public:
    queue<Node*> q;
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur == NULL && q.empty()) {
                return root;
            } else if (cur == NULL) {
                q.push(NULL);
            } else {
                cur->next = q.front();
                if(cur->left != NULL) {
                    q.push(cur->left);
                }
                if(cur->right != NULL) {
                    q.push(cur->right);
                }
            }
        }
       return root;
    }
};
