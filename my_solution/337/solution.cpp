/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 题目的意思是说，二叉树的孩子节点跟父母节点不能同时被盗
// 把一个节点孩子的孩子节点作为子问题的解
// 偷盗的时候可以选择隔一个或者隔两个
// 或者说，如果一个点的孩子节点的偷盗金额数目之和大于父节点，就不偷该节点了
// 对于每个节点，需要存两部分数据，偷这个节点的收益和不偷它的收益
// 偷这个节点的收益 = 不偷左孩子的收益 + 不偷右孩子的收益 + 偷自己的收益
// 不偷这个节点的收益 = max(不偷左孩子的收益, 偷左孩子的收益) + max(不偷右孩子的收益, 偷右孩子的收益)
// class Solution {
// public:
//     struct robber{
//         int stole;
//         int unstole;
//     };
//     void postorderTraversal(TreeNode* root, unordered_map<TreeNode*, robber>& nodeMap){
//         if(root->left != nullptr) postorderTraversal(root->left, nodeMap);
//         if(root->right != nullptr) postorderTraversal(root->right, nodeMap);
//         int stoleLC = nodeMap[root->left].stole, unstoleLC = nodeMap[root->left].unstole;
//         int stoleRC = nodeMap[root->right].stole, unstoleRC = nodeMap[root->right].unstole;

//         int stole = unstoleLC + unstoleRC + root->val;
//         int unstole = max(stoleLC, unstoleLC) + max(stoleRC, unstoleRC);
//         nodeMap[root] = {stole, unstole};
//     }
//     int rob(TreeNode* root) {
//         if(root == nullptr) return 0;
//         unordered_map <TreeNode*, robber> nodeMap;
//         // 把空节点的存进去
//         nodeMap[nullptr] = {0, 0};
//         // 采用后续遍历
//         postorderTraversal(root, nodeMap);
//         return max(nodeMap[root].stole, nodeMap[root].unstole);
//     }
// };


// 啊其实并不需要使用一个哈希表来存，直接作为后序遍历时候的返回值就好了
// 改进后的代码如下：
class Solution {
public:
    struct robber{
        int stole;
        int unstole;
    };
    robber postorderTraversal(TreeNode* root){
        robber robLeft = {0, 0}, robRight = {0, 0};
        if(root->left != nullptr) robLeft = postorderTraversal(root->left);
        if(root->right != nullptr) robRight = postorderTraversal(root->right);

        int stole = robLeft.unstole + robRight.unstole + root->val;
        int unstole = max(robLeft.stole, robLeft.unstole) 
                        + max(robRight.stole, robRight.unstole);
        return {stole, unstole};
    }
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        // 采用后续遍历
        robber r = postorderTraversal(root);
        return max(r.stole, r.unstole);
    }
};