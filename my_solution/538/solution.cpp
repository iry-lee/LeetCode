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
// 中序遍历二叉搜索树
// 把树中的节点的指针存在vector中，然后倒序加起来就可以了
/*
class Solution {
public:
    void middleorderTraverse(TreeNode* root, vector<TreeNode*>& nodeList){
        if(root == nullptr) return;
        middleorderTraverse(root->left, nodeList);
        nodeList.push_back(root);
        middleorderTraverse(root->right, nodeList);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> nodeList;
        middleorderTraverse(root, nodeList);
        int len = nodeList.size();
        for(int i = len-2; i >= 0; i--)
            nodeList[i]->val += nodeList[i+1]->val;
        return root;
    }
};
*/

// 甚至不用全存，直接反中序遍历，只存上一个遍历过的节点的指针就可以了
class Solution {
private:
    TreeNode * temp = nullptr;
public:
    TreeNode *convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        convertBST(root->right);
        if(temp!=nullptr) root->val += temp->val;
        temp = root;
        convertBST(root->left);
        return root;
    }
};