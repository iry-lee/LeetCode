/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
// 如果某一个位置都有值，则求和；
// 如果某一个位置只有一个树有值，则把有值的那个枝杈接过来，同时停止遍历
// 如果某一个位置都没有值，则直接停止遍历。
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 返回t1，将t2合并过来
        if(t1 == nullptr && t2 == nullptr) return nullptr;
        if(t1 == nullptr && t2 != nullptr) return t2;
        else if(t1 != nullptr && t2 == nullptr) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};