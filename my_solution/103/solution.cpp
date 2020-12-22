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
private:
    vector<vector<int>> ans;
public:
    void ParentFirst(TreeNode * root, int level){
        if(root == nullptr) return;
        if(ans.size() > level){
            ans[level].push_back(root->val);
        }
        else{
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        ParentFirst(root->left, level+1);
        ParentFirst(root->right, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 先做层次遍历
        ParentFirst(root, 0);
        // 再隔一行调整一下顺序
        for(int i = 1; i < ans.size(); i+=2){
            int n = ans[i].size();
            for(int j = 0; j < n/2; j++){
                swap(ans[i][j], ans[i][n-1-j]);
            }
        }
        return ans;
    }
};

// 我的想法是，先按层遍历，每一层得到一个一维数组
// 然后再将该逆序的层逆序


/*

在评论区看到一个不错的方法：@bakezq
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.push(root);

        bool lr = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size, 0);
            while (size--) {
                root = q.front(); q.pop();
                level[lr ? level.size() - size - 1 : size] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(move(level));
            lr = !lr;
        }

        return res;
    }
};

*/