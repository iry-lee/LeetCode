class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
};

// 与121题一样，可以在上面代码的基础上，进一步优化空间复杂度：
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  ans = 0, len = prices.size();
        if(len == 0) return ans;

        int dp0 = 0-prices[0];     // 持有股票
        int dp1 = 0;               // 不持有股票
        // 持有股票 --卖出股票--> 不持有股票，在卖出股票的过程中，获得收益
        // 不持有股票 --买入股票--> 持有股票
        for(int i = 1; i < len; i++){
            int temp = dp0;
            dp0 = max(dp0, dp1-prices[i]);
            dp1 = max(dp1, temp + prices[i]);
        }
        return dp1;
    }
};