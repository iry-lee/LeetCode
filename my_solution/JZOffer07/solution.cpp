/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 我的utils中没有对二叉树的相关支持，所以直接就在leetcode上的写的然后测试的。
// 下面的这种方法实际的运行时间有点慢，主要是被vector所拖累，如果在递归的过程中传递的是标号
// 而不是vector的话，速度会快很多。
// 但本题的目的主要是学习这种方法，具体实现就不再细究。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        // 正式开始后面的计算
        int i = 0;
        vector<int> lpreorder, rpreorder, linorder, rinorder;
        for(i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]) break;
        }
        // 划分新的preorder和inorder
        for(int j = 0; j < i; j++){
            linorder.push_back(inorder[j]);
            lpreorder.push_back(preorder[j+1]);
        }
        for(int j = i+1; j < inorder.size(); j++){
            rinorder.push_back(inorder[j]);
            rpreorder.push_back(preorder[j]);
        }
        // 得到左右子树
        TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = preorder[0];
        root->left = buildTree(lpreorder, linorder);
        root->right = buildTree(rpreorder, rinorder);
        return root;
    }
};

