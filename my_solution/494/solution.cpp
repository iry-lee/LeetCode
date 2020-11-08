// 可以使用递归求解，那么每个位置都有两种可能，取正或者取负
// 如果nums的长度为n，那么需要遍历2^n种情况
// 在这个问题的基础上，可以先求出来nums[i, n-1]的和，作为取值范围的参考，方便剪枝操作
// 但是想这种只求个数，不求详细的解的内容的，考虑动态回归应该是可以的
// 建立一个dp数组，里面存储上一个状态的可能的情况
// 在可能的情况中，看是否有结果满足当前情况，上面递归的剪枝方法也可以参考一下
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0){
            if(S == 0) return 1;
            else return 0;
        }
        vector<int> sums(nums.size()+1, 0);
        for(int i = (int)nums.size()-1; i >= 0; i--)
            sums[i] = sums[i+1] + nums[i];
        sums.pop_back();
        map<int, int> dpMap; // 存放的是<大小，次数>
        // 初始化状态
        dpMap[nums[0]] += 1;
        dpMap[-nums[0]] += 1;
        for(int i = 1; i < nums.size(); i++){
            map<int, int> tempMap;
            for(auto ite = dpMap.begin(); ite != dpMap.end(); ite++){
                int a = ite->first + nums[i];
                int b = ite->first - nums[i];
                // a一定小于b
                if(a - sums[i] <= S && a + sums[i] >= S) tempMap[a] += ite->second;
                if(b - sums[i] <= S && b + sums[i] >= S) tempMap[b] += ite->second;
            }
            dpMap = tempMap;
        }
        if(dpMap.find(S) != dpMap.end()) return dpMap[S];
        else return 0;
    }
};
*/

// 看了官方题解以后真正的动态规划
// 这里可以用官方题解的这种动态规划的原因是，这里数组和不会超过1000
// 有状态转移方程 dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]];
// 这里i表示进行到了nums中的第i个数，j表示当前的和为j
class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000 || S < -1000) return 0;
        if(nums.size() == 0){
            if(S == 0) return 1;
            else return 0;
        }
        vector<int> dp (2001, 0);
        vector<int> tempdp (2001, 0);
        // 初始化
        dp[nums[0] + 1000] += 1;
        dp[-nums[0] + 1000] += 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j <= 2000; j++){
                if(j - nums[i] >= 0) tempdp[j] = dp[j-nums[i]];
                if(j + nums[i] <= 2000) tempdp[j] += dp[j+nums[i]];
            }
            dp = tempdp;
        }
        return dp[S+1000];
    }
};