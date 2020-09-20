/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 【迭代】
class Solution{
public:
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(root == nullptr) return true;
        
        q1.push(root);
        q2.push(root);
        while(!q1.empty() && !q2.empty()){
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            q1.pop();
            q2.pop();

            if(t1 == nullptr && t2 == nullptr) continue;
            else if(t1 == nullptr || t2 == nullptr) return false;
            else if(t1->val != t2->val) return false;

            q1.push(t1->left);
            q1.push(t1->right);
            q2.push(t2->right);
            q2.push(t2->left);
        }
        return true;
    }
};
// 【递归】
// class Solution {
// public:
//     bool func(TreeNode *left, TreeNode *right){
//         if(left == nullptr && right == nullptr) return true;
//         else if(left == nullptr || right == nullptr) return false;

//         if(left->val != right->val) return false;
//         else return func(left->right, right->left) && func(left->left, right->right);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(root == nullptr) return true;
//         return func(root->left, root->right);
//     }
// };