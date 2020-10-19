// 【改进后的动态规划】时间复杂度为O(mn)
// 与279题相似，还是O(n^2)与O(n√n)的区别
// 这里假设硬币有m种，则是O(n^2)与O(nm)的区别
// 原因：因为是在之前某一个amount之上增加一个硬币，所以只需要遍历所有可能的硬币的面值。
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 这里让dp[i]对应amount为i的时候的结果
        int dp[amount+1];
        memset(dp, -1, sizeof(dp));
        // 然后把硬币的数量初始化进去
        for(int c : coins)
            if(c <= amount) dp[c] = 1;
        dp[0] = 0;
        // 开始真正的动态规划
        for(int i = 1; i <= amount; i++){
            if(dp[i] != -1) continue;
            int ct = INT_MAX;
            // 这里循环查找的是硬币的面值
            for(int j = 0; j < coins.size(); j++){
                int coin = coins[j];
                if(coin > i) continue;  // 这里没有用break是因为coins不一定是单调递增的
                if(dp[i-coin] >= 0 && ct > dp[i-coin] + 1) ct = dp[i-coin] + 1;
            }
            if(ct < INT_MAX) dp[i] = ct;
            else dp[i] = -1;
        }
        // for(int i = 0; i < amount+1; i++) cout << dp[i] << " ";
        return dp[amount];
    }
};

// 【最初使用的动态规划】 时间复杂度为O(n^2)
// 运行超时
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         // 这里让dp[i]对应amount为i的时候的结果
//         int dp[amount+1];
//         memset(dp, -1, sizeof(dp));
//         // 然后把硬币的数量初始化进去
//         for(int c : coins)
//             if(c <= amount) dp[c] = 1;
//         dp[0] = 0;
//         // 开始真正的动态规划
//         for(int i = 0; i <= amount; i++){
//             int ct = INT_MAX;
//             for(int j = 0; j <= i / 2; j++){
//                 if(dp[j] >= 0 && dp[i-j] >= 0 && dp[j] + dp[i-j] < ct)  
//                     ct = dp[j] + dp[i-j];
//             }
//             if(ct < INT_MAX) dp[i] = ct;
//         }
//         return dp[amount];
//     }
// };