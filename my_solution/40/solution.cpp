// 本题使用39题的思路的话，问题是本题给定的数组中有重复的数字，
// 假如给定数组{1,1,1,5}，target=6，那么就会出现{{1,6},{1,6},{1,6}}
// 在上一题的基础上，可以先排序，每个分支情况带有次数，比如上面，就只是分成情况，1和5
// 即遇到重复数字以后，先取一个进来，或者干脆一个都不取，直接跳到下一个

class Solution {
public:
    vector<vector<int>> func(vector<int>& candidates, int begin, int target){
        // cout << begin << endl;
        vector<vector<int>> ans;
        // 把begin及此后出现的数字存在hash中
        // hashmap中存放的是数值和它的开始位置
        unordered_map<int, int> hashmap;
        for(int i = begin; i < candidates.size(); i++){
            // cout << i << endl;
            if(hashmap.find(candidates[i]) == hashmap.end())
                hashmap[candidates[i]] = i;
        }
        unordered_map<int, int>::iterator ite = hashmap.begin();
        for( ; ite != hashmap.end(); ite++){
            // cout << ite->first << ": " << ite->second << endl;
            if(target == ite->first){
                vector<int> temp(1, ite->first);
                ans.push_back(temp);
            }
            else if(target >= 2 * ite->first) {
                // 因为排过序，这里可以做一下剪枝，
                // 如果target - ite->first < ite->first也不行
                vector<vector<int>> subans = func(candidates, ite->second + 1, target - ite->first);
                if(subans.size() > 0){
                    for(int i = 0; i < subans.size(); i++){
                        subans[i].push_back(ite->first);
                        ans.push_back(subans[i]);
                    }
                }
            }
        }
        return ans;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 这里正序排跟倒序排，可能也不一样
        sort(candidates.begin(), candidates.end());
        return func(candidates, 0, target);
    }
};