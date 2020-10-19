/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 这个题应该可以递归求解？
// 需要求每个子树的左右子树的深度？以及穿过左右子树的根节点的最短路径？
// 这个题可以这么想，最长的路径可能不穿过根节点，但是一定穿过某个子树的根节点
// 将所有的节点的解都求出来，然后找其中的最大值就好了
// 当然这里也可以利用子树的深度做一个剪枝

// 一个节点的最长路径长度可以递归求解，最长路径长度 = 2 + 左子树深度 + 右子树深度
// 在求每个节点的最长路径长度的时候，把最大值存下来
// 深度也可以递归求解，一个子树的 深度 = 1 + max{左子树深度，右子树深度}
// 所以函数递归，把深度作为返回值就可以了

class Solution {
private:
    int maxDiameter = 0;
public:
    int depthOfTree(TreeNode* root){
        if(root == nullptr) return -1;
        else{
            // cout << root->val << endl;
            int leftDepth = depthOfTree(root->left);
            int rightDepth = depthOfTree(root->right);
            if(maxDiameter < leftDepth + rightDepth + 2) 
                maxDiameter = leftDepth + rightDepth + 2;
            return 1 + max(leftDepth, rightDepth);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depthOfTree(root);
        return maxDiameter; 
    }
};