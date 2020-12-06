// 本题可以看作是深度优先搜索+回溯
/*
class Solution {
private:
    int res = 0;
public:
    void bfs(vector<int>& nums, int target, int pathLen){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int newLen = pathLen + nums[i];
            if(newLen == target) res++;
            else if(newLen < target){
                bfs(nums, target, newLen);
            }
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        // path 存放目标数组，而且为了降低时间复杂度，规定path[0]存放的是当前的和
        int pathLen = 0;
        bfs(nums, target, pathLen);
        return res;
    }
};
*/

// 这是一个完全背包的问题
class Solution{
private:
    long long Module = 100000000007;
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp (target+1, 0);

        // base case:
        // 这里base case就是全初始化为0

        // other case:
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                int delta = i - nums[j];
                if(delta == 0) dp[i] += 1;
                else if(delta > 0) {
                    dp[i] += dp[delta];
                    dp[i] %= Module;
                }
            }
        }
        // for(int d : dp) cout << d << " ";
        return (int)dp[target];
    }
};