/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 【中序遍历】：
// 知识点：二叉搜索树的中序遍历是有序的。因此可以通过二叉树的中序遍历来判断这是不是一个二叉搜索树
// （直接用94题写的中序遍历
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
    bool isValidBST(TreeNode *root){
        if(root == nullptr) return true;
        vector <int> inorder = inorderTraversal(root);
        for(int i = 0; i < (int)inorder.size() - 1; i++){
            if(inorder[i] >= inorder[i+1]) return false; 
        }
        return true;
    }
};
// 【递归】：
// 判断规则：
// 左节点、当前节点、右节点依次增加
// 左子树的最大值小于当前节点，右子树的最小值，大于当前节点；
// 左右子树也为二叉搜索树
// class Solution {
// public:
//     int maxValue(TreeNode* root){
//         while(root->right != nullptr)
//             root = root->right;
//         return root->val;
//     }
//     int minValue(TreeNode* root){
//         while(root->left !=nullptr)
//             root = root->left;
//         return root->val;
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root == nullptr) return true;

//         if(root->left != nullptr){
//             if(root->left->val >= root->val) return false;
//             int lmax = maxValue(root->left);
//             if(lmax >= root->val) return false; 
//         }
//         if(root->right != nullptr){
//             if(root->right->val <= root->val) return false;
//             int rmin = minValue(root->right);
//             if(rmin <= root->val) return false;
//         }
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };