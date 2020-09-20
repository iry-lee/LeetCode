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
// 【迭代解法】
// 前序遍历可以使用队列
// 后序遍历可以使用栈
// 中序遍历用双端队列？
class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * temp = st.front();
            if(temp->left != nullptr){
                st.pop();
                if(temp->right != nullptr) st.push(temp->right);
                st.push(temp);
                st.push(temp->left);
                temp->right = nullptr;
                temp->left = nullptr;
            }
            else{
                res.push_back(temp->val);
                st.pop();
                if(temp->right != nullptr) st.push(temp->right);
            }
        }
        return res;
    }
};

// 【经典递归解法】
/*
class Solution {
public:
    void traversal (vector<int> & res, TreeNode *root){
        if(root == nullptr) return;
        traversal(res, root->left);
        res.push_back(root->val);
        traversal(res, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        traversal(res, root);
        return res;
    }
};
*/