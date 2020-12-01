/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // 这里可以使用队列来实现
    string serialize(TreeNode* root) {
        string result;
        result.append("[");
        if(root == nullptr){
            result.append("]");
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();
            if(front != nullptr){
                result.append(to_string(front->val));
                q.push(front->left);
                q.push(front->right);
            }
            else result.append("null");
            if(!q.empty()) result.append(",");

        }
        result.append("]");
        return result;
    }

    // Decodes your encoded data to tree.
    // 感觉也可以通过队列来解决
    TreeNode* deserialize(string data) {
        // cout << data;
        int i = 1;  // 把'['吃掉
        queue<TreeNode*> q;
        TreeNode * head = nullptr;
        while(data[i] != ']'){
            int len = 0;
            while(data[i+len] != ',' && data[i+len] != ']'){
                len++;
            }
            string temp = data.substr(i, len);
            if(temp == "null") q.push(nullptr);
            else{
                TreeNode * temp_node = (TreeNode*)malloc(sizeof(TreeNode));
                temp_node->val = stoi(temp);
                temp_node->left = nullptr;
                temp_node->right = nullptr;
                q.push(temp_node);
            }
            if(data[i + len] == ']') break;
            else i = i + len + 1;
        }
        if(q.empty()) return head;
        head = q.front();
        q.pop();
        queue<TreeNode*> treeQ;  // 里面不存在nullptr
        treeQ.push(head);
        while(!treeQ.empty()){
            TreeNode * temp_node = treeQ.front();
            treeQ.pop();
            TreeNode * left_node, * right_node;
            if(!q.empty()){
                left_node = q.front();
                q.pop();
            }
            else left_node = nullptr;
            if(!q.empty()){
                right_node = q.front();
                q.pop();
            }
            else right_node = nullptr;
            temp_node->left = left_node;
            temp_node->right = right_node;
            if(left_node != nullptr) treeQ.push(left_node);
            if(right_node != nullptr) treeQ.push(right_node);
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));