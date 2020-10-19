// 盲猜这题又是动态规划
// 原问题P(i)的解 = [第i天买入，j天后卖出，冷冻期k天][子问题P(i+j+k+1)]
// 其中j=0表示不作买入，此时冷冻期k>=0，如果j>=1，则k>=1
// 但是这里可以规定冷冻期最多为1天，因为后面的子问题的最优解中，可能也会以1天冷冻期开头
// 所以只需要变动j来确定最优解
// 也就是说，如若发生交易行为，至少要花费两天的时间
// 只保留子问题的解，即收益，子问题中如何操作股票不关心

// 【我的动态规划】时间复杂度O(n^2)
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if(len == 0) return 0;
//         int dp [len+2], ans = 0;    // dp中存储的是利润，+2是为初始化后面的部分
//         memset(dp, 0, sizeof(dp));
//         for(int i = len-1; i >= 0; i--){
//             int max;
//             // 如果不买入
//             if(i+2 <= len) max = dp[i+1];
//             else max = 0;
//             for(int j = 1; j <= len - 1 - i; j++)
//                 if(prices[i+j] - prices[i] + dp[i+j+2] > max)
//                     max = prices[i+j] - prices[i] + dp[i+j+2];
//             dp[i] = max;
//             if(max > ans) ans = max;
//         }
//         return ans;
//     }
// };

// 【官方题解给的动态规划】时间复杂度O(n)
// 官方题解中提供的方法存储下来更多的状态信息，从而降低了时间复杂度
// 状态0：持有股票
// 状态1：无股票，但是处于冷冻期
// 状态2：无股票，也不在冷冻期
// 对于每个状态，分别存储该状态下的最高收益
// 买入操作产生的是负收益——这个很重要，刚刚没想清楚就不知道怎么做

// 因为只需要存储前一天的信息，所以可以优化一下空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        // 0：持有股票
        // 1：冷冻期
        // 2：不持有股票也不处于冷冻期
        int dp[2][3], ans = 0;  // 这里对空间做了一个优化
        // 初始化
        dp[0][0] = -1*prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        // 开始计算
        for(int i = 1; i < len; i++){
            // 每过一天，三个状态都可以做一次转换
            // 每次转换，如果产生了更高的收益，就可以更新dp数组中的值
            dp[1][0] = max(dp[0][0], dp[0][2]-prices[i]);
            dp[1][1] = dp[0][0] + prices[i];
            dp[1][2] = max(dp[0][1], dp[0][2]);
            // 交换一下信息
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
            dp[0][2] = dp[1][2];
        }
        return max(dp[0][1], dp[0][2]);
    }
};

// 有一个很好的总结
// https://blog.csdn.net/weixin_44413191/article/details/106346918