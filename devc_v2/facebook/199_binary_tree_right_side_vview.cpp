/*

199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

*/

//Solution - 1 (BFS)

    int k = 0;
    typedef struct TreeNode* Node;
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> rightView;
        // getRightView(root, rightView, 0);
        queue<Node> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node s = q.front();
            q.pop();
            if (s == NULL) {
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            if (s->left != NULL) {
                q.push(s->left);
            }
            if (s->right != NULL) {
                q.push(s->right);
            }
            if (q.front() == NULL) {
                rightView.push_back(s->val);
            }
        }
        return rightView;

// Solution-2: Recursion

void getRightView(Node node, vector<int> &rightView,int curLevel)     {
        if (node == NULL) {
            return;
        }
        if (curLevel >= k) {
            rightView.push_back(node->val);
            k++;
        }
        if (node->right != NULL) {
            getRightView(node->right, rightView, curLevel + 1);
        }
        if (node->left!= NULL) {
            getRightView(node->left, rightView, curLevel + 1);
        }
    }
