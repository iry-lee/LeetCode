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
// 官方的一个方法：找前序节点
// 思想跟我的方法类似，也是找右子树的前序是左子树的最右节点
class Solution {
public:
    void flatten(TreeNode *root){
        if(root == nullptr) return;
        if(root->left != nullptr){
            TreeNode *temp = root->left;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            temp->right = root->right;
            root->right = root->left;
            root->left = nullptr;  // 左子树记得置空
        }
        flatten(root->right);
    }
};


// 把二叉树变成一个右侧的单链表，而且要求是原地
// 左子树的最右节点接右子树的根节点
// 我的这个方法类似于一个前序遍历
// class Solution {
// private:
//     TreeNode* ptr;
// public:
//     void func(TreeNode* root){
//         if(root == nullptr) return;
//         TreeNode *left = root->left;
//         TreeNode *right = root->right;
//         ptr->left = nullptr;    // 记得将左子树置为空
//         if(left != nullptr){
//             ptr->right = left;
//             ptr = left;
//             func(ptr);
//         }
//         if(right != nullptr) {
//             ptr->right = right;
//             ptr = right;
//             func(ptr);
//         }
//     }
//     void flatten(TreeNode* root) {
//         ptr = root;
//         func(root);
//     }
// };