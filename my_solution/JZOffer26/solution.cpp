/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 注意，这个二叉树不是二叉排序树
class Solution {
public:
    bool sameStructure(TreeNode* A, TreeNode* B){
        if(B == nullptr) return true;
        if(A == nullptr) return false;
        if(A->val != B->val) return false;
        return sameStructure(A->left, B->left) && sameStructure(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;
        // 先在A中找B的根节点
        queue<TreeNode*> tnq;
        tnq.push(A);
        bool findRoot = false;
        while(!tnq.empty()){
            if(tnq.front()->val == B->val && sameStructure(tnq.front(), B)){
                findRoot = true; break;
            }
            else{
                if(tnq.front()->left != nullptr) tnq.push(tnq.front()->left);
                if(tnq.front()->right != nullptr) tnq.push(tnq.front()->right);
                tnq.pop();
            }
        }
        if(!findRoot) return false;
        return sameStructure(tnq.front(), B);
    }
};