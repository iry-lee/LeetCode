/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int dleft = maxDepth(root->left);
        int dright = maxDepth(root->right);
        if(dleft > dright) return dleft + 1;
        else return dright + 1; 
    }
};

/*

深度优先：当前层根据下一层的情况得到当前层的状态，在这过程中，不需要传递当前层的状态。
广度优先：当前层收到上一层的状态，然后把当前层的状态添加进去，再传给下一层。

可以注意到的一个点是，深度优先遍历，各个层的状态信息是保存在函数内的参数中，或者说是在函数栈中；而广度优先遍历，则需要通过函数的参数传递状态，数据是保存在参数栈中。

*/