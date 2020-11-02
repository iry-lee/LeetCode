// 没太有思路，看到提示里的这一串条件，感觉这个题的时间复杂度应该要不低
// 感觉这个题可以使用递归来求解，但是感觉会有点慢
class Solution {
public:
    void func(vector<int>& candidates, vector<vector<int>>& res, vector<int> v, int target){
        if(target < candidates.front()) return;
        else{
            for(auto i: candidates){
                // 这里需要做一个剪枝，防止情况有重复
                if(v.size() > 0 && i < v.back()) continue;
                if(i < target){
                    v.push_back(i);
                    func(candidates, res, v, target-i);
                    v.pop_back();
                }
                else if(i == target){
                    v.push_back(i);
                    res.push_back(v);
                    return;
                }
                else break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 先做一遍排序
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        func(candidates, res, temp, target);
        return res;
    }
};