// 【之前我的方法】
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         if(prices.size() <= 1) return res;
//         int min = prices[0];
//         for(int item : prices){
//             if(min > item) min = item;
//             if(item - min > res) res = item - min;
//         }
//         return res;
//     }
// };

// 看完 https://blog.csdn.net/weixin_44413191/article/details/106346918 用它的方法重新做一遍
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  ans = 0, len = prices.size();
        if(len == 0) return ans;

        int dp[len][2];
        dp[0][0] = 0-prices[0];     // 持有股票
        dp[0][1] = 0;               // 不持有股票
        for(int i = 1; i < len; i++){
            dp[i][0] = max(dp[i-1][0], 0 - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            if(dp[i][1] > ans) ans = dp[i][1];
        }
        return ans;
    }
};

// 在上面的基础上再提高一下空间使用效率，从O(n)的空间复杂度，提高到了O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  ans = 0, len = prices.size();
        if(len == 0) return ans;

        int dp[2];
        dp[0] = 0-prices[0];     // 持有股票
        dp[1] = 0;               // 不持有股票
        for(int i = 1; i < len; i++){
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = max(dp[0], 0 - prices[i]);
            if(dp[1] > ans) ans = dp[1];
        }
        return ans;
    }
};