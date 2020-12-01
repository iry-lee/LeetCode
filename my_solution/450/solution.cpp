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
class Solution {
private:
    TreeNode* parent = nullptr;
public:
    TreeNode* findNode(TreeNode* root, int key){
        if(root == nullptr) return root;
        else if(root->val == key) return root;
        else{
            parent = root;
            if(root->val > key) return findNode(root->left, key);
            else return findNode(root->right, key);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = findNode(root, key);
        if(target != nullptr){
            if(target->right != nullptr){
                TreeNode* temp = target->right;
                while(temp->left != nullptr){
                    temp = temp->left;
                }
                temp->left = target->left;
                target->left = nullptr;
            }
            else{
                target->right = target->left;
                target->left = nullptr;
            }
            if(parent == nullptr) return target->right;
            else if(parent->left == target) parent->left = target->right;
            else parent->right = target->right;
        }
        return root;
    }
};