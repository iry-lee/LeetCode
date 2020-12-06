class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<vector<int>> statistic, int n, vector<int>& path){
        int len = statistic.size();
        if(n == 0){
            res.push_back(path);
            return;
        }
        n--;
        for(int i = 0; i < len; i++){
            if(statistic[i][1] > 0){
                statistic[i][1]--;
                path.push_back(statistic[i][0]);
                dfs(statistic, n, path);
                statistic[i][1]++;
                path.pop_back();
            }
        }   
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 需要先统计一下有几种数字，分别出现了几次
        vector<vector<int>> statistic;
        // 用以哈希表记录数字以及其对应的在statistic中的下标
        unordered_map<int, int> hash;
        for(int n : nums){
            if(hash.find(n) != hash.end()){
                int posi = hash[n];
                statistic[posi][1]++;
            }
            else{
                hash[n] = statistic.size();
                vector<int> temp;
                temp.push_back(n);
                temp.push_back(1);
                statistic.push_back(temp);
            }
        }

        // 准备作为遍历的输入
        vector<int> path;
        dfs(statistic, (int)nums.size(), path);

        return res;
    }
};

// 先统计每个数字的出现次数，然后以数字为单位去遍历，来防止重复
// 题解中给出的方法是通过排序，从而可以跳过后面与当前数字相同的数字，也很好的思路
// 我的解法中传递了一些二维数组，这个过程中的复制会增加时间