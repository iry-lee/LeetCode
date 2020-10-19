// 【我的方法】找规律
// 其实是有规律可以遵循的
// 遇到2 4 8 16 …… 这些数字的时候
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0) return ans;
        ans.push_back(1);
        if(num == 1) return ans;
        int flag = 2;
        for(int i = 2, j = 0; i <= num; i++){
            ans.push_back(ans[j++] + 1);
            if(j == flag){
                flag = j*2;
                j = 0;
            }
        }
        return ans;
    }
};