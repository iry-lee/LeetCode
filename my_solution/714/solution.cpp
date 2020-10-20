class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(!len) return 0;
        // 初始化状态
        // 也可以初始化dp[-1]的状态，初始化为
        // dp[-1][0] = INT_MIN, dp[-1][1] = 0;
        // 然后后面从 i = 0 开始
        int dp[len][2];
        dp[0][0] = 0 - prices[0];
        dp[0][1] = 0; 
        for(int i = 1; i < len; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        // for(int i = 0; i < len; i++) cout << dp[i][0] << " ";
        // cout << endl;
        // for(int i = 0; i < len; i++) cout << dp[i][1] << " ";
        // cout << endl;
        return dp[len-1][1];
    } 
};
// 同样此代码可以进一步优化dp的空间复杂度，在这里不再赘述了