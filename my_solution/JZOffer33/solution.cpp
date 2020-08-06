#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty() || postorder.size() == 1) return true;
        int rootVal = postorder[postorder.size()-1], i = 0, j = 0;
        vector<int> left, right;
        for(; i < postorder.size() - 1; i++){
            if (postorder[i] > rootVal) break;
            else left.push_back(postorder[i]);
        }
        for(j = i; j < postorder.size() - 1; j++){
            if (postorder[j] < rootVal) return false;
            else right.push_back(postorder[j]);
        }
        return verifyPostorder(left) && verifyPostorder(right);
    }
};
/* 一些测试用例：
1. 空数组
[]
2. 单链表
[1,2,3,4,5,6,7,8]
3. 正确用例：
[1,3,2,6,5]
4. 错误用例：
[1,6,3,2,5]
 */