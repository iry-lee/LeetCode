// 迭代法，用01表示字符是否出现
// 略...

// 经典做法：dfs回溯法
// 每一层是一个字符，在这一层，有两种情况，把这个字符加入结果中，或者不加入
class Solution{ 
public:
    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> v, int begin){
        int n = nums.size();
        if(begin == n){
            res.push_back(v);
            return;
        }
        // 取这个元素
        v.push_back(nums[begin]);
        dfs(res, nums, v, begin+1);
        // 不取这个元素
        v.pop_back();
        dfs(res, nums, v, begin+1);
    }
    vector<vector<int>> subsets(vector<int> nums){
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, nums, temp, 0);
        return res;
    }
};


// 我的方法
/*
class Solution {
public:
    void func(vector <vector<int>> &res, vector<int> & nums, vector<int> v, int len, int begin, int end){
        if(len == 0) res.push_back(v);
        else{
            for(int i = begin; i <= end; i++){
                if(end - i + 1 < len) break;
                else{
                    v.push_back(nums[i]);
                    func(res, nums, v, len-1, i+1, end);
                    v.pop_back();
                }
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> res;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            vector<int> temp;
            func(res, nums, temp, i, 0, n-1);
        }
        return res;
    }
};
*/