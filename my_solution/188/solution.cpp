// 按照123题的思路，将穷举两次交易改写成循环就好了
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int len = prices.size();
//         if(!len || !k) return 0;
//         // 初始化状态
//         int dp[len][k][2];
//         for(int i = 0; i < k; i++){
//             dp[0][i][0] = -prices[0];
//             dp[0][i][1] = 0;
//         }
//         for(int i = 1; i < len; i++){
//             dp[i][0][0] = max(dp[i-1][0][0], 0 - prices[i]);
//             dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] + prices[i]);
//             for(int j = 1; j < k; j++){
//                 dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] - prices[i]);
//                 dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] + prices[i]);
//             }
//         }
//         return dp[len-1][k-1][1];
//     }
// };

// 这个不优化空间复杂度不行了，如果直接提交的话，会发生 stack overflow

class Solution {
public:
    int maxProfit_infi(vector<int>& prices) {
        int  ans = 0, len = prices.size();
        if(len == 0) return ans;

        int dp[len][2];
        dp[0][0] = 0-prices[0];     // 持有股票
        dp[0][1] = 0;               // 不持有股票
        // 持有股票 --卖出股票--> 不持有股票，在卖出股票的过程中，获得收益
        // 不持有股票 --买入股票--> 持有股票
        for(int i = 1; i < len; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[len-1][1];
    }
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(!len || !k) return 0;
        // 用之前做过的无数多次交易的来优化k特别大的情况，如果不做优化确实会爆栈以及超时
        // 因为题目的条件中k都能到10^9了
        if (k > len / 2) return maxProfit_infi(prices);
        // 初始化状态
        int dp[k][2];
        for(int i = 0; i < k; i++){
            dp[i][0] = -prices[0];
            dp[i][1] = 0;
        }
        for(int i = 1; i < len; i++){
            for(int j = k-1; j > 0; j--){
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
                dp[j][0] = max(dp[j][0], dp[j-1][1] - prices[i]);
            }
            dp[0][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = max(dp[0][0], 0 - prices[i]);
        }
        return dp[k-1][1];
    }
};